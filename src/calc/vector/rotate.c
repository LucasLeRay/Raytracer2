/*
** rotate.c<calc> for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:43:46 2017 Thery Fouchter
** Last update Sat May 27 16:47:01 2017 Thery Fouchter
*/

#include "raytracer.h"

/*
**	Rotations Matrix by angles (A,B,C)
**
**	[Rx]-----------------	[Ry]----------------	[Rz]-------------
**
**	1	0	0	cosB	0	sinB	cosC	-sinC	0
**	0	cosA	-sinA	0	1	0	sinC	cosC	0
**	0	sinA	cosA	-sinB	0	cosB	0	0	1
**
**	[RxRy]---------------------------		[Rz]-------------
**
**	cosB		0	sinB			cosC	-sinC	0
**	sinAsinB	cosA	-sinAcosB		sinC	cosC	0
**	-cosAsinB	sinA	cosAcosB		0	0	1
**
**	[RxRyRz]-------------------------------------------------     [v]
**
**	cosBcosC		-cosBsinC		sinB		x
**	sinAsinBcosC+cosAsinC	-sinAsinBsinC+cosAcosC	-sinAcosB	y
**	-cosAsinBcosC+sinAsinC	cosAsinBsinC+sinAcosC	cosAcosB	z
**
**	[RxRyRz][x]------------------------------------------------------
**
**	x*cosBcosC - y*cosBsinC + z*sinB
**	x*(sinAsinBcosC+cosAsinC) + y*(-sinAsinBsinC+cosAcosC) - z*sinAcosB
**	x*(-cosAsinBcosC+sinAsinC) + y*(cosAsinBsinC+sinAcosC) + z*cosAcosB
**
**	[RzRy]---------------------------		[Rx]-------------
**
**	cosCcosB	-sinC	cosCsinB		1	0	0
**	sinCcosB	cosC	sinCsinB		0	cosA	-sinA
**	-sinB		0	cosB			0	sinA	cosA
**
**	[RzRyRx]-------------------------------------------------     [v]
**
**	cosCcosB	-sinCcosA+cosCsinBsinA	sinCsinA+cosCsinBcosA	x
**	sinCcosB	cosCcosA+sinCsinBsinA	-cosCsinA+sinCsinBcosA	y
**	-sinB		cosBsinA		cosBcosA		z
**
**	[RxRyRz][x]------------------------------------------------------
**
**	x*cosCcosB + y*(-sinCcosA+cosCsinBsinA) + z*(sinCsinA+cosCsinBcosA)
**	x*sinCcosB + y*(cosCcosA+sinCsinBsinA) + z*(-cosCsinA+sinCsinBcosA)
**	x*(-sinB) + y*cosBsinA + z*cosBcosA
**
*/

float	safe_angle(float angle)
{
  if ((angle > 0 && angle > 360) || (angle < 0 && angle < 360))
    angle = (int)angle % 360;
  return (angle);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	v;
  float		rad;
  float		a;
  float		b;
  float		c;

  a = safe_angle(angles.x) * (rad = M_PI / 180.0);
  b = safe_angle(angles.y) * rad;
  c = safe_angle(angles.z) * rad;
  v.x = to_rotate.x;
  v.y = to_rotate.y;
  v.z = to_rotate.z;
  to_rotate.x = v.x * cos(c) * cos(b)
    + v.y * (-sin(c) * cos(a) + cos(c) * sin(b) * sin(a))
    + v.z * (sin(c) * sin(a) + cos(c) * sin(b) * cos(a));
  to_rotate.y = v.x * sin(c) * cos(b)
    + v.y * (cos(c) * cos(a) + sin(c) * sin(b) * sin(a))
    + v.z * (-cos(c) * sin(a) + sin(c) * sin(b) * cos(a));
  to_rotate.z = v.x*(-sin(b)) + v.y*cos(b)*sin(a) + v.z*cos(b)*cos(a);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	v;
  float		rad;
  float		a;
  float		b;
  float		c;

  a = safe_angle(angles.x) * (rad = M_PI / 180.0);
  b = safe_angle(angles.y) * rad;
  c = safe_angle(angles.z) * rad;
  v.x = to_rotate.x;
  v.y = to_rotate.y;
  v.z = to_rotate.z;
  to_rotate.x = v.x * cos(b) * cos(c) - v.y * cos(b) * sin(c) + v.z * sin(b);
  to_rotate.y = v.x * (sin(a) * sin(b) * cos(c) + cos(a) * sin(c))
    + v.y * (-sin(a) * sin(b) * sin(c) + cos(a) * cos(c))
    - v.z * sin(a) * cos(b);
  to_rotate.z = v.x * (-cos(a) * sin(b) * cos(c) + sin(a) * sin(c))
    + v.y * (cos(a) * sin(b) * sin(c) + sin(a) * cos(c))
    + v.z * cos(a) * cos(b);
  return (to_rotate);
}

/*
** Rotate_angle:
** - angle (in degrees)
** - nb:
**	* 1	:	x
**	* 2	:	y
**	* 3	:	z
**	* other	:	x
*/

sfVector3f	rotate_angle(sfVector3f v, float angle, int nb)
{
  if ((angle > 0 && angle > 360) || (angle < 0 && angle < 360))
    angle = (int)angle % 360;
  angle *= (M_PI / 180.0);
  if (nb == 2)
    {
      v.x = (v.x * cos(angle)) + (v.z * sin(angle));
      v.z = (v.z * cos(angle)) - (v.x * sin(angle));
    }
  else if (nb == 3)
    {
      v.x = (v.x * cos(angle)) - (v.y * sin(angle));
      v.y = (v.x * sin(angle)) + (v.y * cos(angle));
    }
  else
    {
      v.y = (v.y * cos(angle)) - (v.z * sin(angle));
      v.z = (v.y * sin(angle)) + (v.z * cos(angle));
    }
  return (v);
}
