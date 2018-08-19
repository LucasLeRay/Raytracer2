/*
** events.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 20:56:11 2017 Thery Fouchter
** Last update Thu May 25 23:05:56 2017 Thery Fouchter
*/

#include "raytracer.h"

static int	handle_move_events(t_raytracer *ray)
{
  int		did_smg;
  int		speed;

  did_smg = 0;
  speed = (ray->opti == 1 ? MOVE_SPEED_OPTI : MOVE_SPEED);
  if (sfKeyboard_isKeyPressed(KEY_MOVE_FRONT) == sfTrue)
    did_smg += move_eye(ray, 0, speed, 0);
  if (sfKeyboard_isKeyPressed(KEY_MOVE_BACK) == sfTrue)
    did_smg += move_eye(ray, 0, -speed, 0);
  if (sfKeyboard_isKeyPressed(KEY_MOVE_LEFT) == sfTrue)
    did_smg += move_eye(ray, -speed, 0, 0);
  if (sfKeyboard_isKeyPressed(KEY_MOVE_RIGHT) == sfTrue)
    did_smg += move_eye(ray, speed, 0, 0);
  if (sfKeyboard_isKeyPressed(KEY_MOVE_UP) == sfTrue)
    did_smg += move_eye(ray, 0, 0, speed);
  if (sfKeyboard_isKeyPressed(KEY_MOVE_DOWN) == sfTrue)
    did_smg += move_eye(ray, 0, 0, -speed);
  return (did_smg);
}

static int	handle_rot_events(t_raytracer *ray)
{
  int		did_smg;
  int		speed;

  did_smg = 0;
  speed = (ray->opti == 1 ? ROT_SPEED_OPTI : ROT_SPEED);
  if (sfKeyboard_isKeyPressed(KEY_TURN_CAMERA_UP) == sfTrue)
    did_smg += change_rot_camera(ray, 0, -speed, 0);
  if (sfKeyboard_isKeyPressed(KEY_TURN_CAMERA_DOWN) == sfTrue)
    did_smg += change_rot_camera(ray, 0, speed, 0);
  if (sfKeyboard_isKeyPressed(KEY_TURN_CAMERA_LEFT) == sfTrue)
    did_smg += change_rot_camera(ray, 0, 0, speed);
  if (sfKeyboard_isKeyPressed(KEY_TURN_CAMERA_RIGHT) == sfTrue)
    did_smg += change_rot_camera(ray, 0, 0, -speed);
  if (sfKeyboard_isKeyPressed(KEY_ROT_CAMERA_LEFT) == sfTrue)
    did_smg += change_rot_camera(ray, speed, 0, 0);
  if (sfKeyboard_isKeyPressed(KEY_ROT_CAMERA_RIGHT) == sfTrue)
    did_smg += change_rot_camera(ray, -speed, 0, 0);
  return (did_smg);
}

int	handle_win_events(t_raytracer *ray, sfEvent *event)
{
  int	did_smg;

  did_smg = 0;
  if (event->type == sfEvtClosed || (event->key.code == KEY_ESCAPE))
    sfRenderWindow_close(ray->visual->window);
  else if (event->type == sfEvtKeyPressed && event->key.code == KEY_RESET)
    did_smg += reset_raytracer(ray);
  else if (event->type == sfEvtKeyPressed && event->key.code == KEY_OPTI)
    {
      if (ray->opti == 2)
	ray->opti = 1;
      else
	ray->opti = 2;
      did_smg += 1;
    }
  else if (handle_chess_events(ray, event))
    ++did_smg;
  return (did_smg);
}

int	handle_key_events(t_raytracer *ray)
{
  int	did_smg;

  did_smg = handle_move_events(ray);
  did_smg += handle_rot_events(ray);
  if (!ray->opti)
    ray->opti = did_smg;
  return (did_smg);
}

int	handle_chess_events(t_raytracer *ray, sfEvent *event)
{
  if (ray->play_chess && event->type == sfEvtKeyPressed
      && (event->key.code == KEY_CHESS_LOCK
	  || event->key.code == KEY_CHESS_MOVE
	  || event->key.code == KEY_CHESS_DOWN
	  || event->key.code == KEY_CHESS_RIGHT
	  || event->key.code == KEY_CHESS_LEFT
	  || event->key.code == KEY_CHESS_UP))
    {
      ray->glob->send = init_send(ray->glob->send);
      ray->glob = exec_event(ray->glob, event);
      get_chess_piece(ray->chess_board, ray->glob->send->mouse);
      move_chess_piece(ray->chess_board, ray->chess_choose, -1,
		       ray->glob->send->mouse);
      if (ray->glob->send->moved)
	move_chess_piece(ray->chess_board, NULL,
			 ray->glob->send->from, ray->glob->send->to);
      free(ray->glob->send);
      return (1);
    }
  return (0);
}
