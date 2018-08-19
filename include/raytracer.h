/*
** raytracer.h for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 11:45:38 2017 Thery Fouchter
** Last update Sun May 28 23:20:21 2017 Guts
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# define MAIN_TITLE		"raytracer2"
# define BITS_PER_PXL		32
# define WIN_STYLE		(sfResize | sfClose)
# define NBR_THREAD		4

# define ABS(x)			(((x) < 0) ? -(x) : (x))
# define SQ(x)			((x) * (x))
# define MAX(x, y)		((x) > (y) ? (x) : (y))
# define MIN(x, y)		((x) < (y) ? (x) : (y))
# define CLAMP(a, mi, ma)	MIN(MAX(a, mi), ma)
# define MIX(a, b, mix)		(((b) * (mix)) + ((a) * (1.0 - (mix))))

# define LIN(x, y, z)		((x) + ((z) * ((y) - (x))))
# define SMOOTH(x, y, z)	(LIN((x), (y), (z) * (z) * (3 - (2 * (z)))))

# define MAX_INT		0xFFFFFFFFFFFF
# define MOVE_SPEED		25
# define MOVE_SPEED_OPTI	5
# define ROT_SPEED		10
# define ROT_SPEED_OPTI		1
# define OPTI_JUMP		4

# define KEY_ESCAPE		sfKeyEscape
# define KEY_RESET		sfKeySpace
# define KEY_OPTI		sfKeyR
# define KEY_MOVE_FRONT		sfKeyUp
# define KEY_MOVE_RIGHT		sfKeyRight
# define KEY_MOVE_LEFT		sfKeyLeft
# define KEY_MOVE_BACK		sfKeyDown
# define KEY_MOVE_UP		sfKeyPageUp
# define KEY_MOVE_DOWN		sfKeyPageDown
# define KEY_TURN_CAMERA_LEFT	sfKeyQ
# define KEY_TURN_CAMERA_RIGHT	sfKeyD
# define KEY_TURN_CAMERA_UP	sfKeyZ
# define KEY_TURN_CAMERA_DOWN	sfKeyS
# define KEY_ROT_CAMERA_LEFT	sfKeyA
# define KEY_ROT_CAMERA_RIGHT	sfKeyE
# define KEY_CHESS_LOCK		sfKeyW
# define KEY_CHESS_MOVE		sfKeyX
# define KEY_CHESS_DOWN		sfKeyM /*L*/
# define KEY_CHESS_RIGHT	sfKeyO /*M*/
# define KEY_CHESS_LEFT		sfKeyL /*K*/
# define KEY_CHESS_UP		sfKeyK /*O*/

# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define D_GREEN		"\033[6m"
# define WHITE			"\033[7m"
# define CYAN			"\x1b[36m"
# define RESET			"\033[0m"

# define COEF_AMB		1.0
# define COEF_DIF		1.0
# define COEF_SPE		1.0
# define COEF_TRA		0.0
# define COEF_RER		0.0
# define COEF_REX		0.0
# define LIGHT			0.0
# define EFFECT			0
# define PATTERN		0
# define MATERIAL		0
# define TEXTURE		NULL
# define SIZE_X			10
# define SIZE_Y			10
# define SIZE_Z			10

# define SPHERE_T		1
# define CONE_T			2
# define CYLINDER_T		3
# define PLANE_T		4
# define MITER_T		5
# define MOEBIUS_T		6
# define PYRAMID_T     		7
# define LIGHT_T     		8
# define HYPERBOLE_T   		9
# define PARABOLOIDE_T 		10
# define BLACKHOLE_T   		11
# define BOHEMIAN_T   		12
# define CHUBS_T   		13
# define VOID_CUBE_T   		14
# define DEVIL_T   		15
# define DEFAULT_TYPE		0

# define INFINITE		(1e10)
# define G			(0.0667384)

# define PAWN			'P'
# define KNIGHT			'N'
# define BISHOP			'B'
# define ROOK			'R'
# define QUEEN			'Q'
# define KING			'K'
# define NAMEP			"pawn"
# define NAMEN			"knight"
# define NAMEB			"bishop"
# define NAMER			"rook"
# define NAMEQ			"queen"
# define NAMEK			"king"

# define ROW			9
# define END			70
# define START			0

# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <math.h>
# include <pthread.h>
# include "get_next_line.h"
# include <string.h>

typedef struct s_dichotomy	t_dichotomy;
typedef struct s_ppm_texture	t_ppm_texture;
typedef struct s_light		t_light;
typedef struct s_objects	t_objects;
typedef struct s_parsing	t_parsing;
typedef int (**PARAMS)(t_parsing*, char*, int);
typedef struct s_parser		t_parser;
typedef struct s_obj		t_obj;
typedef struct s_my_framebuffer	t_my_framebuffer;
typedef struct s_visual		t_visual;
typedef struct s_camera		t_camera;
typedef struct s_ray		t_ray;
typedef struct s_raytracer	t_raytracer;
typedef struct s_piece		t_piece;
typedef struct s_all		t_all;
typedef struct s_case		t_case;
typedef struct s_glob		t_glob;
typedef struct s_send		t_send;

typedef enum			e_pattern
{
  e_pat_squares_1 = 1,
  e_pat_squares_2 = 2,
  e_pat_circle_1 = 4,
  e_pat_circle_2 = 8,
  e_pat_vline = 16,
  e_pat_hline = 32,
}				t_pattern;

typedef enum			obj_type
{
  e_null = 0,
  e_sphere = 1,
  e_cone = 2,
  e_cylinder = 3,
  e_plane = 4,
  e_miter = 5,
  e_moebius = 6,
  e_pyramid = 7,
  e_light = 8,
  e_hyperbole = 9,
  e_paraboloide = 10,
  e_blackhole = 11,
  e_bohemian = 12,
  e_chubs = 13,
  e_void_cube = 14,
  e_devil = 15,
}				t_obj_type;

struct				s_dichotomy
{
  double			l;
  double			r;
  double			mid;
  int				sl;
  int				sr;
  int				smid;
};

struct				s_light
{
  sfColor			color;
  sfColor			ambient;
  sfColor			diffuse;
  sfColor			specular;
  sfVector3f			light_dir;
  sfVector3f			light_pos;
  double			k_ambient;
  double			k_diffuse;
  double			k_specular;
};

struct				s_ppm_texture
{
  sfColor			**image;
  sfVector2i			size;
};

struct				s_objects
{
  t_objects			*assembly;
  int				id;
  int				side;
  char				*name;
  sfVector3f			pos;
  sfVector3f			pos_temp;
  sfVector3f			inc_pos;
  sfColor			color;
  sfColor			color_ambient;
  sfColor			color_diffuse;
  sfColor			color_specular;
  float				coef_ambient;
  float				coef_diffuse;
  float				coef_specular;
  float				coef_transparency;
  float				coef_reflexion;
  float				coef_refraction;
  int				specular_power;
  int				perlin_noise;
  float				perlin_freq;
  int				perlin_seed;
  float				light;
  sfColor			light_color;
  unsigned int			effect;
  unsigned int			pattern;
  sfColor			pattern_color;
  unsigned int			material;
  t_ppm_texture			**texture;
  int				type;
  sfVector3f			size;
  sfVector3f			rotation;
  sfVector3f			timed_rotation;
  sfVector3f			speed;
  int				check_speed;
  int				mass;
  struct s_objects		*next;
};

struct				s_parsing
{
  sfMusic			*music;
  t_ppm_texture			*wallpaper_ppm;
  char				*wallpaper;
  int				rendering;
  int				render_distance;
  int				max_recursion;
  int				antialiasing;
  int				line_calc;
  t_objects			*objects;
  int				line_n;
};

struct				s_parser
{
  int				win_x;
  int				win_y;
  sfVector3f			cam_pos;
  sfVector3f			cam_rot;
  float				cam_dist_to_plane;
  char				*conf_file;
  char				*sett_file;
  t_parsing			*parsing;
};

struct				s_my_framebuffer
{
  sfUint8			*pixels;
  int				width;
  int				height;
  struct s_my_framebuffer	*next;
};

struct				s_visual
{
  t_my_framebuffer		*framebuffer;
  sfRenderWindow		*window;
  sfSprite			*sprite;
  sfTexture			*texture;
  sfVector2i			screen_size;
};

struct				s_camera
{
  sfVector3f			pos;
  sfVector3f			rot;
  float				dist_to_plane;
};

struct				s_ray
{
  sfVector2f			screen_pos;
  sfColor			color;
  sfVector3f			ori;
  sfVector3f			dir;
  sfVector3f			pos_hit;
  sfVector3f			nrm_hit;
  int				depth;
  int				inside_obj;
};

struct				s_raytracer
{
  t_parser			*parser;
  t_visual			*visual;
  t_camera			*camera;
  t_objects			*obj;
  t_objects			**lights;
  int				opti;
  t_ppm_texture			*img;
  int				play_chess;
  t_glob			*glob;
  t_objects			*chess_board;
  t_objects			*chess_choose;
};

struct				s_glob
{
  t_all				*all;
  t_all				*cpy;
  t_piece			*list;
  int				lock;
  int				mouse;
  int				actual;
  t_send			*send;
};

struct				s_case
{
  t_case			*next;
  int				place;
};

struct				s_piece
{
  t_case			*cases;
  t_piece			*next;
  int				place;
  int				name;
  char				prop;
  char				*desc;
};

struct				s_all
{
  char				*map;
  t_piece			*white;
  t_piece			*black;
  int				turn;
  int				check;
};

struct				s_send
{
  char				check;
  t_case			*cases;
  int				mouse;
  char				lock;
  int				from;
  int				to;
  char				moved;
  char				castle;
};

extern pthread_t		g_tid[NBR_THREAD];
extern int			g_pos[NBR_THREAD];

/*		raytracer.c				*/
int			raytracer(int, char **);
/*		raytracer_utils.c			*/
int			init_raytracer(t_raytracer *);
int			reset_raytracer(t_raytracer *);
/*		events.c				*/
int			handle_win_events(t_raytracer *, sfEvent *);
int			handle_key_events(t_raytracer *);
int			handle_chess_events(t_raytracer *, sfEvent *);
/*		events_utils.c				*/
int			border_int(float *, int, int, int);
int			move_eye(t_raytracer *, int, int, int);
int			change_rot_camera(t_raytracer *, int, int, int);
/*		obj.c					*/
t_objects		**get_lights(t_objects *);
/*		assembly.c				*/
t_objects		*ass(t_objects *, sfVector3f, sfVector3f);

/*	PARSING						*/
/*		parsing.c				*/
t_parser		*parsing(int, char **);
/*		lucas					*/
void			print_parsing(t_parsing *);
t_parsing		*parse_configuration(char*, char*);
int			fill_conf(t_parsing*, int, int);
void			memset_parsing(t_parsing *);
int			fill_music(t_parsing *, char *,
				   int, char *);
int			fill_wallpaper(t_parsing *, char *,
				       int, char *);
int			fill_rendering(t_parsing *, char *, int,
				       char *);
int			my_printf(const char*, ...);
int			open_file(char*);
t_objects		*insert_node(t_objects *, char *);
int			fill_quality(t_parsing*, int, int, char*);
char			*clean_line(char*);
int			my_strcmp(char*, char*);
char			*my_strcat(char *, char *, char);
int			my_strncmp(char*, char*, int);
char			*my_strcpy(char*);
void			my_memset(char*, int);
int			my_atoi(char*);
int			my_strlen(char*);
void			init_node(t_objects*, char*);
int			fill_objects(t_parsing*, int);
char			*get_next_line(int);
char			*my_strdup(char*);
int			print_error_syntax(int, char*);
int			parse_objects(t_parsing*, int, char**,
				      PARAMS);
int			check_syntax_color(char*, char*, int);
int			find_color(t_parsing*, char*, sfColor*);
int			op_pos(t_parsing*, char*, int);
int			op_color(t_parsing*, char*, int);
int			op_color_ambient(t_parsing*, char*, int);
int			op_color_diffuse(t_parsing*, char*, int);
int			op_color_specular(t_parsing*, char*, int);
int			op_coef_ambient(t_parsing*, char*, int);
int			op_coef_diffuse(t_parsing*, char*, int);
int			op_coef_specular(t_parsing*, char*, int);
int			op_coef_transparency(t_parsing*, char*, int);
int			op_coef_reflexion(t_parsing*, char*, int);
int			op_coef_refraction(t_parsing*, char*, int);
int			op_light(t_parsing*, char*, int);
int			op_light_color(t_parsing*, char*, int);
int			op_effect(t_parsing*, char*, int);
int			op_material(t_parsing*, char*, int);
int			op_pattern(t_parsing*, char*, int);
int			op_texture(t_parsing*, char*, int);
int			check_syntax_effects(char*, char*, int);
int			check_syntax_coef(char*, char*, int);
int			check_syntax_pos(char*, char*, int);
float			my_atof(char*);
int			op_inherit(t_parsing*, char*, int);
int			op_type(t_parsing*, char*, int);
int			op_rotation(t_parsing*, char*, int);
int			op_size(t_parsing*, char*, int);
int			op_specular_power(t_parsing*, char*, int);
int			op_perlin_noise(t_parsing*, char*, int);
int			op_perlin_freq(t_parsing*, char*, int);
int			op_perlin_seed(t_parsing*, char*, int);
int			op_pattern_color(t_parsing*, char*, int);
int			op_timed_rotation(t_parsing*, char*, int);
int			op_mass(t_parsing*, char*, int);
int			op_speed(t_parsing*, char*, int);

/*	RAYTRACE					*/
/*		cube_mapping.c				*/
sfVector2f		convert_xyz_to_cube_uv(sfVector3f, int *);
sfColor			calc_cube_mapping(t_raytracer *, t_ray *, t_objects *);
/*		normal_mapping.c			*/
sfColor			calc_normal_mapping(t_raytracer *, t_ray *,
					    t_objects *);

/*		pattern.c				*/
int			surface_pattern(float, float, int);
int			surface_pattern_xy(sfVector3f, int);
int			surface_pattern_xz(sfVector3f, int);
int			surface_pattern_yz(sfVector3f, int);
sfColor			apply_pattern_color(sfColor, sfColor, sfVector3f, int);
/*		intersect.c				*/
float			inter_obj_size(t_objects *, sfVector3f,
				       sfVector3f, float);
float			inter_obj(t_objects *, sfVector3f, sfVector3f);
t_objects		*get_closest_intersect(t_objects *, sfVector3f,
					       sfVector3f, float *);
/*		raytrace.c				*/
int			setup_ray(t_raytracer *, t_ray *, sfVector2f);
sfColor			trace_ray(t_raytracer *, t_ray *);
int			raytrace(t_raytracer *);
/*		raytrace_calc.c				*/
sfVector3f		calc_normal(t_objects *, sfVector3f, sfVector3f);
sfVector3f		calc_pos_hit(sfVector3f, sfVector3f, float);
int			calc_ray_vectors(t_ray *, t_objects *, float);
/*		thread.c				*/
void			*raytrace_thread(void *);
int			raytrace_thread_scene(t_raytracer *);
/*		refraction.c				*/
sfVector3f		calc_refraction(sfVector3f, sfVector3f, float, float);
int			trace_refraction_ray(t_raytracer *, t_ray *,
					     t_objects *);
/*		reflection.c				*/
sfVector3f		calc_reflection(sfVector3f, sfVector3f);
int			trace_reflection_ray(t_raytracer *, t_ray *,
					     t_objects *);
/*		super_sampling.c			*/
sfColor			super_sampling(t_raytracer *, sfVector2f,
				       sfColor, t_ray *);
/*		light.c					*/
sfColor			trace_light_ray(t_raytracer *, t_ray *, t_objects *);
sfColor			calc_phong_color(t_ray *, t_objects *,
					 t_light *, t_objects *);
sfColor			calc_ambient(t_objects *, double *);
sfColor			calc_diffuse(t_objects *, t_ray *,
				     sfVector3f, double *);
sfColor			calc_specular(t_objects *, t_ray *,
				      sfVector3f, double *);

/*	SFML						*/
/*		framebuffer.c				*/
t_my_framebuffer	*init_framebuffer(int, int);
/*		my_put_pixel.c				*/
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
/*		window.c				*/
sfRenderWindow		*init_window(int, int);

/*	VISUAL						*/
/*		visual.c				*/
t_visual		*init_visual(t_parser *);
int			update_visual(t_visual *, int);
/*		camera.c				*/
t_camera		*init_camera(t_parser *);

/*	CALC						*/
/*		color.c					*/
sfColor			mult_color(sfColor, float);
sfColor			mix_color(sfColor, float, sfColor, float);
sfColor			create_color(int, int, int, int);
/*		calc_dir_vector.c			*/
sfVector3f		calc_dir_vector(float, sfVector2i, sfVector2i);
/*		random.c				*/
int			randomize(int, int);
/*		perlin_noise.c				*/
sfColor			calc_perlin_noise(t_raytracer *, t_ray *, t_objects *);
float			perlin_noise(sfVector2f, float, int, int);
float			noise(float, float, int);
int			noise_table(int, int, int);

/*	CALC/LIGHT					*/
/*		light.c					*/
float			get_light_coef(sfVector3f, sfVector3f);

/*	CALC/OBJS					*/
/*		cone.c					*/
float			intersect_cone(sfVector3f, sfVector3f, float);
sfVector3f		get_normal_cone(sfVector3f, float);
/*		cylinder.c				*/
float			intersect_cylinder(sfVector3f, sfVector3f, float);
sfVector3f		get_normal_cylinder(sfVector3f);
/*		objs_utils.c				*/
float			get_delta(float, float, float);
/*		plane.c					*/
float			intersect_plane(sfVector3f, sfVector3f);
sfVector3f		get_normal_plane(int);
/*		sphere.c				*/
float			intersect_sphere(sfVector3f, sfVector3f, float);
sfVector3f		get_normal_sphere(sfVector3f);
sfVector3f		get_normal_obj_sphere(t_objects *, sfVector3f);
/*		miter.c					*/
float			intersect_miter(sfVector3f, sfVector3f, float);
/*		moebius.c				*/
float			intersect_moebius(sfVector3f, sfVector3f, float);
/*		hyperbole.c				*/
float			intersect_hyperboloide(sfVector3f, sfVector3f, float);
/*		bohemian.c				*/
float			intersect_bohemian(sfVector3f, sfVector3f, float);
/*		chubs.c					*/
float			intersect_chubs(sfVector3f, sfVector3f, float);
/*		void_cube.c				*/
float			intersect_void_cube(sfVector3f, sfVector3f, float);
/*		devil.c					*/
float			intersect_devil(sfVector3f, sfVector3f, float);
/*		paraboloide.c				*/
float			intersect_paraboloide(sfVector3f, sfVector3f, float);
/*		solver.c				*/
double			find_solution(double *, int);
int			launch_solver(double *, double *, int);
double			rooting_calculation(double *, int, double, double);
/*		solver_degree.c				*/
int			remove_degree(double *, int);
int			solver_degree_1(double *, double *);
int			solver_degree_2(double *, double *);
/*		solver_dichotomy.c			*/
double			polynomial_effect(double *, int, double);
double			dichoto_loop(double *, int, t_dichotomy *);

/*	CALC/VECTOR					*/
/*		rotate.c				*/
float			safe_angle(float);
sfVector3f		rotate_xyz(sfVector3f, sfVector3f);
sfVector3f		rotate_zyx(sfVector3f, sfVector3f);
sfVector3f		rotate_angle(sfVector3f, float, int);
/*		vector.c				*/
float			v_dot(sfVector3f, sfVector3f);
float			v_len(sfVector3f);
sfVector3f		v_nrm(sfVector3f);
int			v_diff(sfVector3f, sfVector3f);
/*		vector_inits.c				*/
sfVector2f		create_2vector(float, float);
sfVector3f		c3v(float, float, float);
sfVector3f		create_3vector(float, float, float);
sfVector3f		create_null_3vector(void);
/*		vector_operations_nb.c			*/
sfVector3f		v_add_nb(sfVector3f, float);
sfVector3f		v_sub_nb(sfVector3f, float);
sfVector3f		v_mult_nb(sfVector3f, float);
sfVector3f		v_div_nb(sfVector3f, float);
/*		vector_operations_v.c			*/
sfVector3f		v_add_v(sfVector3f, sfVector3f);
sfVector3f		v_sub_v(sfVector3f, sfVector3f);
sfVector3f		v_mult_v(sfVector3f, sfVector3f);
sfVector3f		v_div_v(sfVector3f, sfVector3f);
/*		read_PPM.c				*/
t_ppm_texture		*read_PPM(char*);
void			check_header(int, sfVector2i*);
/*		physics			*/
int			apply_physics(t_raytracer *);
void			calc_vector_coll(sfVector3f, t_objects *, t_objects *);
sfVector3f		calc_final_vector(sfVector3f, t_objects *);
sfVector3f		calc_direction(t_objects *, t_objects *);
double			calc_newton(t_objects *, t_objects *, sfVector3f);
sfVector3f		apply_force_vector(sfVector3f, double, float);
void			activate_timed_rotation(t_raytracer*);

/*	CHESS						*/
/*		chess.c					*/
int			init_chess(t_raytracer *);
/*		chess_move.c				*/
int			move_assembly(t_objects *, sfVector3f, int);
int			move_chess_piece(t_objects *, t_objects *, int, int);
t_objects		*get_chess_piece(t_objects *, int);
/*		chess_board.c				*/
t_objects		*create_chess_board(sfVector3f);
/*		chess_utils.c				*/
sfVector3f		get_chess_pos(t_objects *, int, int);
int			set_objcolor_side(t_objects *, int);
t_objects		*append_to_obj(t_objects *, t_objects *, int);
/*		chess_pawn.c				*/
t_objects		*create_chess_pawn(int, sfVector3f);
/*		chess_knight.c				*/
t_objects		*create_chess_knight(int, sfVector3f);
/*		chess_bishop.c				*/
t_objects		*create_chess_bishop(int, sfVector3f);
/*		chess_rook.c				*/
t_objects		*create_chess_rook(int, sfVector3f);
/*		chess_queen.c				*/
t_objects		*create_chess_queen(int, sfVector3f);
/*		chess_king.c				*/
t_objects		*create_chess_king(int, sfVector3f);

/*	CHESS_ALGO					*/
/*		init_chess.c				*/
t_glob			*init_chess_game(void);
char			*get_empty_map(void);
void			aff_list(t_case *);
/*		init_piece.c				*/
int			init_rook(t_piece **, char);
int			init_knight(t_piece **, char);
int			init_bishop(t_piece **, char);
int			init_king(t_piece **, char);
int			init_queen(t_piece **, char);
/*		board.c					*/
char			*clean_map(char *);
void			show_all(t_all *);
void			put_on_board(t_all **);
void			show_o(t_piece *);
/*		controls.c				*/
int			control_bishop(t_piece **, char *);
int			control_king(t_piece **, char *);
int			control_queen(t_piece **, char *);
int			control_rook(t_piece **, char *);
int			control_knight(t_piece **, char *);
/*		get_controls.c				*/
int			add_case(t_case **, int);
int			get_limit_case(int, int, char *, t_case **);
int			get_case(int, t_case **, char *);
int			get_controls(t_piece **, char *);
/*		pawn.c					*/
int			init_pawn(t_piece **, char, int);
int			control_pawn(t_piece **, char *);
int			move_pawn_forward(t_all *, t_piece *, t_case **);
int			get_pawn_move(t_all *, t_case **, t_piece *);
/*		free.c					*/
void			full_cases_free(t_all **);
void			full_piece_free(t_all **);
void			free_cases(t_piece **);
int			a_remove_piece(t_piece **, int);
int			remove_piece(t_all **, int);
/*		king.c					*/
t_glob			*move_rook_castle(t_glob *, int, int);
t_glob			*exec_castle(t_glob *, int);
int			is_king_attacked(t_all *, int, int);
int			can_king_move(t_all *);
int			get_castle(t_all *, t_case **, t_piece *);
/*		copy.c					*/
int			full_piece_copy(t_all **, t_all *);
int			a_piece_copy(t_piece **, t_piece *);
int			piece_copy(t_piece **, t_piece *);
int			copy_all(t_all **, t_all *);
/*		moves.c					*/
int			get_piece_move(t_all *, t_piece **, int, int);
int			get_normal_move(t_all *, t_case **, t_piece *);
int			check_taken(t_piece *, int);
t_piece			*get_piece_name(t_all *, int);
/*		exec_move.c				*/
t_glob			*exec_move(t_glob *);
t_glob			*change_after_exec(t_glob *);
/*		mate.c					*/
int			is_controlled(t_piece *, int);
int			free_glob(t_glob *);
int			is_mate(t_all *);
/*		utils.c					*/
int			ret(char *);
void			aff_list(t_case *);
int			is_in_list(t_case *, int);
void			aff_map(char *, int, t_case *);
/*		music.c					*/
void			init_music(t_raytracer*);
/*		send.c					*/
t_send			*init_send(t_send *);
char			fill_send(int);
void			aff_truc(t_case *);
void			aff_send(t_send *);
/*		principal.c				*/
int			init_color(t_piece **, t_piece **);
t_glob			*exec_event(t_glob *, sfEvent *);
t_glob			*move_mouse(t_glob *, sfEvent *);
int			init_all(t_all **);
/*		lib					*/
void			my_putchar(char c);
int			my_put_nbr(int nb);
int			my_putstr(char *str);
int			my_strlen(char *str);
int			my_getnbr(char *str);
/*		loading					*/
void	loading_screen(t_raytracer*, int, t_my_framebuffer*);
void	init_loading_screen(t_raytracer*, t_my_framebuffer*);
void	loading_done(t_raytracer*, t_my_framebuffer*);

#endif
