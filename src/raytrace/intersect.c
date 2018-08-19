/*
** intersect.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Sun May  7 19:11:46 2017 Thery Fouchter
** Last update Mon May 29 14:15:06 2017 aba yanis
*/

#include "raytracer.h"

float		inter_obj(t_objects *obj,
			  sfVector3f ori,
			  sfVector3f dir)
{
  float		k;

  ori = v_sub_v(ori, obj->pos);
  if (!v_diff(obj->rotation, create_null_3vector()))
    {
      dir = rotate_zyx(dir, obj->rotation);
      ori = rotate_zyx(ori, obj->rotation);
    }
  k = -1.0;
  if (obj->type == e_plane)
    k = intersect_plane(ori, dir);
  else if (obj->type == e_sphere)
    k = intersect_sphere(ori, dir, obj->size.x);
  else if (obj->type == e_cylinder)
    k = intersect_cylinder(ori, dir, obj->size.x);
  else if (obj->type == e_cone)
    k = intersect_cone(ori, dir, obj->size.x);
  return (inter_obj_size(obj, ori, dir, k));
}

float		inter_obj_size(t_objects *obj,
			       sfVector3f ori,
			       sfVector3f dir,
			       float k)
{
  sfVector3f	hit;

  if (k == -1.0)
    return (k);
  else if (obj->type == e_plane)
    {
      hit = calc_pos_hit(ori, dir, k);
      if (v_diff(obj->size, create_3vector(10, 10, 10)));
      else if (hit.x > obj->size.x || hit.x < -obj->size.x
	       || hit.y > obj->size.y || hit.y < -obj->size.y
	       || hit.z > obj->size.z || hit.z < -obj->size.z)
	k = -1.0;
    }
  else if (obj->type == e_cone || obj->type == e_cylinder)
    {
      hit = calc_pos_hit(ori, dir, k);
      if (v_diff(obj->size, create_3vector(10, 10, 10)));
      else if (hit.z >= 0 || hit.z <= -obj->size.z)
	k = -1.0;
    }
  return (k);
}

t_objects	*get_closest_intersect(t_objects *obj,
				       sfVector3f ori,
				       sfVector3f dir,
				       float *ptr_k)
{
  t_objects	*tmp;
  t_objects	*i_obj;
  t_objects	*cobj;
  float		ck;
  float		k;

  cobj = NULL;
  ck = 0;
  tmp = obj;
  while ((i_obj = tmp))
    {
      if ((k = inter_obj(i_obj, ori, dir)) >= 0)
	{
	  if (tmp->assembly)
	    {
	      i_obj = get_closest_intersect(tmp->assembly, ori, dir, &k);
	      i_obj = ((!cobj || (k != -1.0 && k < ck)) ? i_obj : NULL);
	    }
	  ck = (i_obj && (!cobj || k < ck) && (cobj = i_obj)) ? k : ck;
	}
      tmp = tmp->next;
    }
  if (ptr_k)
    *ptr_k = ck;
  return (cobj);
}
