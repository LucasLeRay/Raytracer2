/*
** fill_objects.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Thu Apr 27 13:23:20 2017 Guts
** Last update Sun May 28 21:58:42 2017 Thery Fouchter
*/

#include "raytracer.h"

int	(**init_options2(int (**options)(t_parsing *, char *, int)))
(t_parsing *, char *, int)
{
  options[18] = op_pattern;
  options[19] = op_pattern_color;
  options[20] = op_material;
  options[21] = op_texture;
  options[22] = op_inherit;
  options[23] = op_type;
  options[24] = op_size;
  options[25] = op_rotation;
  options[26] = op_timed_rotation;
  options[27] = op_mass;
  options[28] = op_speed;
  options[29] = NULL;
  return (options);
}

int	(**init_options(void))(t_parsing *, char *, int)
{
  int	(**options)(t_parsing *, char *, int);

  options = malloc(sizeof(*options) * 30);
  options[0] = op_pos;
  options[1] = op_color;
  options[2] = op_color_ambient;
  options[3] = op_color_diffuse;
  options[4] = op_color_specular;
  options[5] = op_coef_ambient;
  options[6] = op_coef_diffuse;
  options[7] = op_coef_specular;
  options[8] = op_coef_transparency;
  options[9] = op_coef_reflexion;
  options[10] = op_coef_refraction;
  options[11] = op_specular_power;
  options[12] = op_perlin_noise;
  options[13] = op_perlin_freq;
  options[14] = op_perlin_seed;
  options[15] = op_light;
  options[16] = op_light_color;
  options[17] = op_effect;
  return (init_options2(options));
}

char	**init_options_list2(char **options_list)
{
  options_list[19] = my_strdup("pattern_color=");
  options_list[20] = my_strdup("material=");
  options_list[21] = my_strdup("texture=");
  options_list[22] = my_strdup("inherit=");
  options_list[23] = my_strdup("type=");
  options_list[24] = my_strdup("size=");
  options_list[25] = my_strdup("rotation=");
  options_list[26] = my_strdup("timed_rotation=");
  options_list[27] = my_strdup("mass=");
  options_list[28] = my_strdup("speed=");
  options_list[29] = NULL;
  return (options_list);
}

char	**init_options_list(void)
{
  char	**options_list;

  options_list = malloc(sizeof(char*) * 30);
  options_list[0] = my_strdup("pos=");
  options_list[1] = my_strdup("color=");
  options_list[2] = my_strdup("color_ambient=");
  options_list[3] = my_strdup("color_diffuse=");
  options_list[4] = my_strdup("color_specular=");
  options_list[5] = my_strdup("coef_ambient=");
  options_list[6] = my_strdup("coef_diffuse=");
  options_list[7] = my_strdup("coef_specular=");
  options_list[8] = my_strdup("coef_transparency=");
  options_list[9] = my_strdup("coef_reflexion=");
  options_list[10] = my_strdup("coef_refraction=");
  options_list[11] = my_strdup("specular_power=");
  options_list[12] = my_strdup("perlin_noise=");
  options_list[13] = my_strdup("perlin_freq=");
  options_list[14] = my_strdup("perlin_seed=");
  options_list[15] = my_strdup("light=");
  options_list[16] = my_strdup("light_color=");
  options_list[17] = my_strdup("effect=");
  options_list[18] = my_strdup("pattern=");
  return (init_options_list2(options_list));
}

int	fill_objects(t_parsing *parsing, int fd)
{
  char	**options_list;
  int	(**options)(t_parsing*, char*, int);
  char	*s;
  int	line_n;

  options_list = init_options_list();
  options = init_options();
  line_n = 1;
  while ((s = get_next_line(fd)))
    {
      if (my_strncmp(s, "OBJ:", 4) == 1)
	{
	  s = get_next_line(fd);
	  parsing->objects = insert_node(parsing->objects, &s[4]);
	  parsing->line_n = line_n;
	  line_n = parse_objects(parsing, fd, options_list, options);
	  line_n++;
	  if (line_n == -1)
	    return (-1);
	}
      line_n++;
    }
  return (0);
}
