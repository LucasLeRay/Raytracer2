##
## Makefile for  in /home/thery/Desktop/raytracer2
## 
## Made by Thery
## Login   <thery.fouchter@epitech.eu>
## 
## Started on  Mon May  1 15:19:30 2017 Thery
## Last update Mon May 29 14:13:57 2017 aba yanis
##

NAME	=	raytracer2
MAIN	=	src/main.c
SRC	=	src/parsing/parse_configuration.c			\
		src/parsing/open_file.c					\
		src/parsing/fill_conf.c					\
		src/parsing/fill_conf_utils.c				\
		src/parsing/fill_quality.c				\
		src/parsing/clean_line.c				\
		src/parsing/essentials_str1.c				\
		src/parsing/essentials_str2.c				\
		src/parsing/essentials_str3.c				\
		src/parsing/my_atoi.c					\
		src/parsing/init_node.c					\
		src/parsing/fill_objects.c				\
		src/parsing/parse_objects.c				\
		src/parsing/print_error.c				\
		src/parsing/src_options/op_pos.c			\
		src/parsing/src_options/op_color.c			\
		src/parsing/src_options/op_color_ambient.c		\
		src/parsing/src_options/op_color_diffuse.c		\
		src/parsing/src_options/op_color_specular.c		\
		src/parsing/src_options/op_coef_ambient.c		\
		src/parsing/src_options/op_coef_diffuse.c		\
		src/parsing/src_options/op_coef_specular.c		\
		src/parsing/src_options/op_coef_transparency.c		\
		src/parsing/src_options/op_coef_reflexion.c		\
		src/parsing/src_options/op_coef_refraction.c		\
		src/parsing/src_options/op_light.c			\
		src/parsing/src_options/op_light_color.c		\
		src/parsing/src_options/op_effect.c			\
		src/parsing/src_options/op_material.c			\
		src/parsing/src_options/op_pattern.c			\
		src/parsing/src_options/op_texture.c			\
		src/parsing/src_options/op_inherit.c			\
		src/parsing/src_options/op_type.c			\
		src/parsing/src_options/op_rotation.c			\
		src/parsing/src_options/op_size.c			\
		src/parsing/src_options/op_specular_power.c		\
		src/parsing/src_options/op_perlin_noise.c		\
		src/parsing/src_options/op_perlin_freq.c		\
		src/parsing/src_options/op_perlin_seed.c		\
		src/parsing/src_options/op_pattern_color.c		\
		src/parsing/src_options/op_timed_rotation.c		\
		src/parsing/src_options/op_mass.c			\
		src/parsing/src_options/op_speed.c			\
		src/raytracer.c						\
		src/raytracer_utils.c					\
		src/events.c						\
		src/events_utils.c					\
		src/obj.c						\
		src/assembly.c						\
		src/loading_screen.c					\
		src/calc/calc_dir_vector.c				\
		src/calc/color.c					\
		src/calc/perlin_noise.c					\
		src/calc/light/light.c					\
		src/calc/objs/cone.c					\
		src/calc/objs/cylinder.c				\
		src/calc/objs/objs_utils.c				\
		src/calc/objs/plane.c					\
		src/calc/objs/sphere.c					\
		src/calc/vector/rotate.c				\
		src/calc/vector/vector.c				\
		src/calc/vector/vector_inits.c				\
		src/calc/vector/vector_operations_nb.c			\
		src/calc/vector/vector_operations_v.c			\
		src/parsing/parsing.c					\
		src/raytrace/pattern.c					\
		src/raytrace/cube_mapping.c				\
		src/raytrace/normal_mapping.c				\
		src/raytrace/raytrace.c					\
		src/raytrace/thread.c					\
		src/raytrace/reflection.c				\
		src/raytrace/refraction.c				\
		src/raytrace/super_sampling.c				\
		src/raytrace/intersect.c				\
		src/raytrace/light.c					\
		src/raytrace/raytrace_calc.c				\
		src/sfml/framebuffer.c					\
		src/sfml/my_put_pixel.c					\
		src/sfml/window.c					\
		src/sfml/music.c					\
		src/utils/get_next_line.c				\
		src/visual/camera.c					\
		src/visual/visual.c					\
		src/visual/read_ppm.c					\
		src/physics/calc_new_pos.c				\
		src/physics/calc_newton.c				\
		src/physics/calc_vector.c				\
		src/physics/activate_timed_rotation.c			\
		src/chess/chess_board.c					\
		src/chess/chess.c					\
		src/chess/chess_move.c					\
		src/chess/chess_pawn.c					\
		src/chess/chess_board.c					\
		src/chess/chess_utils.c					\
		src/chess/chess_knight.c				\
		src/chess/chess_bishop.c				\
		src/chess/chess_rook.c					\
		src/chess/chess_queen.c					\
		src/chess/chess_king.c					\
		src/chess/chess_algo/utils.c				\
		src/chess/chess_algo/send.c				\
		src/chess/chess_algo/principal.c			\
		src/chess/chess_algo/mate.c				\
		src/chess/chess_algo/piece_init.c			\
		src/chess/chess_algo/free.c				\
		src/chess/chess_algo/board.c				\
		src/chess/chess_algo/copy.c				\
		src/chess/chess_algo/moves.c				\
		src/chess/chess_algo/controls.c				\
		src/chess/chess_algo/get_controls.c			\
		src/chess/chess_algo/pawn.c				\
		src/chess/chess_algo/king.c				\
		src/chess/chess_algo/exec_move.c			\
		src/chess/chess_algo/lib/my/my_putchar.c		\
		src/chess/chess_algo/lib/my/my_putstr.c			\
		src/chess/chess_algo/lib/my/my_put_nbr.c		\
		src/chess/chess_algo/lib/my/my_getnbr.c			\
		src/chess/chess_algo/init_chess.c

INC	=	-I include
L	=	1
LIB_1	=	-lm -lpthread -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system lib/my_printf.a
LIB_2	=	-lm -lpthread -lcgraph_prog_full -Llib -lmy_printf
F	=	-W -Wall -Werror -Wextra -pedantic -Wpedantic -Wimplicit -Woverflow

PIMP	=	'Best raytracer ever is '
HISTORY	=	.make_history
BAR	=	100
OTHER	=	''

H_1	=	/------------------------------------------------------------------------------------\\
H_2	=	| 00000  0   0  00000  00000  0   0  0   0  00000  00000  00000  0   0  00000  00000 |
H_3	=	|   0    0   0  0      00  0   0 0   00  0  0   0  0      0   0  0   0  00  0  0     |
H_4	=	|   0    00000  000    0 000    0    0 0 0  0   0  00000  00000  0   0  0 000  000   |
H_5	=	|   0    0   0  0      0  0     0    0  00  0   0      0  0   0  0   0  0  0   0     |
H_6	=	|   0    0   0  00000  0   0    0    0   0  00000  00000  0   0  00000  0   0  00000 |
H_7	=	\------------------------------------------------------------------------------------/

NAM_OBJ	=	$(MAIN:.c=.o)
OBJ	=	$(SRC:.c=.o)

GCC	=	gcc -O3 -o
RUN_VG	=	valgrind
VG	=	-g3
ECHO	=	-e

FF	=	
F_VG	=	
FF_VG	=	
ARGS	=	
IN	=	
IN_F	=	
P_IN	=	
P_OUT	=	
OUT	=	

ifeq ("$(L)", "1")
LIB	=	$(LIB_1)
else
LIB	=	$(LIB_2)
endif
BAR_MAX	=	$(shell echo $(SRC) | grep -o "\.c" | grep -c "\.c")
ifneq ("$(wildcard $(NAM_OBJ) $(OBJ))","")
BAR_INC	=	0
BAR_X	=	$(BAR_MAX)
else
BAR_INC	=	1
BAR_X	=	0
endif
COMPTER	=	$(shell cat $(HISTORY) 2> /dev/null || (echo -ne '0' > $(HISTORY) && echo -ne '0') || echo '0')

0	=	0
1	=	1
C_ESC	=	\033[
BLACK	=	$(C_ESC)0;30m
RED	=	$(C_ESC)0;31m
GREEN	=	$(C_ESC)0;32m
ORANGE	=	$(C_ESC)0;33m
BLUE	=	$(C_ESC)0;34m
PURPLE	=	$(C_ESC)0;35m
CYAN	=	$(C_ESC)0;36m
L_GRAY	=	$(C_ESC)0;37m
D_GRAY	=	$(C_ESC)1;30m
L_RED	=	$(C_ESC)1;31m
L_GREEN	=	$(C_ESC)1;32m
YELLOW	=	$(C_ESC)1;33m
L_BLUE	=	$(C_ESC)1;34m
L_PURP	=	$(C_ESC)1;35m
L_CYAN	=	$(C_ESC)1;36m
WHITE	=	$(C_ESC)1;37m
NC	=	$(C_ESC)0m

all:		$(NAME)

$(NAME):	$(NAM_OBJ) $(OBJ)
ifneq ($(PIMP),)
		@echo -e '$(CYAN)$(PIMP)Creating "$(L_CYAN) $(NAME) $(CYAN)" binary.$(NC)'
		@$(GCC) $@ $^ $(LIB)
ifneq ($(HISTORY),)
		$(eval COMPTER=$(shell echo $$(($(COMPTER)+1))))
		@echo -ne $(COMPTER) > $(HISTORY)
		@echo -e '$(RED)$(PIMP)Compiled $(L_RED)$(COMPTER)$(RED) times !'
endif
		@echo -e '$(D_GRAY)$(PIMP)Done !$(NC)'
else
		$(GCC) $@ $^ $(LIB)
endif

%.o:		%.c
ifneq ($(PIMP),)
		$(eval BAR_X=$(shell echo $$(($(BAR_X)+$(BAR_INC)))))
		@echo -ne '$(YELLOW)$(PIMP)Compiling$(GREEN) '
ifneq ($(BAR),)
		@echo -ne '[$(L_BLUE)'
		@printf "%03d" $$(( $(BAR_X) * $(BAR) / ($(BAR_MAX) + $(BAR_INC)) ))
		@echo -ne '%$(GREEN)] '
endif
		@echo -ne $< | rev | cut -d "/" -f2 | rev | tr -d '\n'
		@echo -ne '/$(L_GREEN)'
		@echo -ne $< | rev | cut -d "/" -f1 | rev | tr -d '\n'
		@echo -ne '\n'
		@$(GCC) $@ $(F) $(FF) $(FF_VG) $(INC) -c $<
else
		$(GCC) $@ $(F) $(FF) $(FF_VG) $(INC) -c $<
endif

clean:
ifneq ($(PIMP),)
		@echo -e '$(ORANGE)$(PIMP)Cleaning junk files.$(NC)'
		@find . -type f -name "*~" -delete -or -name "#*#" -delete -or -name "*.o" -delete
else
		find . -type f -name "*~" -delete -or -name "#*#" -delete -or -name "*.o" -delete
endif

fclean:		clean setup_bar
ifneq ($(PIMP),)
		@echo -e '$(ORANGE)$(PIMP)Cleaning binary.$(NC)'
		@rm -f $(NAME)
else
		rm -f $(NAME)
endif

hclean:		fclean
ifneq ($(HISTORY),)
		@echo -e '$(ORANGE)$(PIMP)Cleaning history (was $(YELLOW)$(COMPTER)$(ORANGE) times).$(NC)'
		@rm -f $(HISTORY)
else
		@echo -e '$(ORANGE)$(PIMP)Can t find history file.$(NC)'
endif

re:		fclean all

$(OTHER):
		$(MAKE) -C $(OTHER) $(ARGS)

run:		$(NAME)
ifneq ($(IN_F),)
ifneq ($(IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) < $(IN_F) > $(OUT) | $(P_OUT)
else
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) < $(IN_F) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) < $(IN_F) | $(P_OUT)
else
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) < $(IN_F)
endif
endif
else
ifneq ($(P_IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		$(P_IN) | ./$(NAME) $(ARGS) < $(IN_F) > $(OUT) | $(P_OUT)
else
		$(P_IN) | ./$(NAME) $(ARGS) < $(IN_F) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		$(P_IN) | ./$(NAME) $(ARGS) < $(IN_F) | $(P_OUT)
else
		$(P_IN) | ./$(NAME) $(ARGS) < $(IN_F)
endif
endif
else
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		./$(NAME) $(ARGS) < $(IN_F) > $(OUT) | $(P_OUT)
else
		./$(NAME) $(ARGS) < $(IN_F) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		./$(NAME) $(ARGS) < $(IN_F) | $(P_OUT)
else
		./$(NAME) $(ARGS) < $(IN_F)
endif
endif
endif
endif
else
ifneq ($(IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) > $(OUT) | $(P_OUT)
else
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS) | $(P_OUT)
else
		echo $(ECHO) $(IN) | ./$(NAME) $(ARGS)
endif
endif
else
ifneq ($(P_IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		$(P_IN) | ./$(NAME) $(ARGS) > $(OUT) | $(P_OUT)
else
		$(P_IN) | ./$(NAME) $(ARGS) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		$(P_IN) | ./$(NAME) $(ARGS) | $(P_OUT)
else
		$(P_IN) | ./$(NAME) $(ARGS)
endif
endif
else
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		./$(NAME) $(ARGS) > $(OUT) | $(P_OUT)
else
		./$(NAME) $(ARGS) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		./$(NAME) $(ARGS) | $(P_OUT)
else
		./$(NAME) $(ARGS)
endif
endif
endif
endif
endif

rerun:		fclean run

valgrind:	rename_vg $(NAME)
ifneq ($(IN_F),)
ifneq ($(IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) > $(OUT) | $(P_OUT)
else
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) | $(P_OUT)
else
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F)
endif
endif
else
ifneq ($(P_IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) > $(OUT) | $(P_OUT)
else
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) | $(P_OUT)
else
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F)
endif
endif
else
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) > $(OUT) | $(P_OUT)
else
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F) | $(P_OUT)
else
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) < $(IN_F)
endif
endif
endif
endif
else
ifneq ($(IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) > $(OUT) | $(P_OUT)
else
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) | $(P_OUT)
else
		echo $(ECHO) $(IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS)
endif
endif
else
ifneq ($(P_IN),)
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) > $(OUT) | $(P_OUT)
else
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) | $(P_OUT)
else
		$(P_IN) | $(RUN_VG) $(F_VG) ./$(NAME) $(ARGS)
endif
endif
else
ifneq ($(OUT),)
ifneq ($(P_OUT),)
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) > $(OUT) | $(P_OUT)
else
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) > $(OUT)
endif
else
ifneq ($(P_OUT),)
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS) | $(P_OUT)
else
		$(RUN_VG) $(F_VG) ./$(NAME) $(ARGS)
endif
endif
endif
endif
endif

revalgrind:	fclean valgrind

rename_vg:
		$(eval FF_VG := $(VG))

setup_bar:
		$(eval BAR_INC := $(1))
		$(eval BAR_X := $(0))

history:
ifneq ($(HISTORY),)
ifneq ($(PIMP),)
		@echo -e '$(RED)Compiled $(L_RED)$(COMPTER)$(RED) times !'
else
		@echo -e 'PIMP variable required for make history!'
endif
else
		@echo -e '$(RED)History $(L_RED)disabled$(RED), enable it with $(L_RED)HISTORY= $(RED)variable!'
endif

help:
ifneq ($(PIMP),)
		@echo -e '$(RED)$(H_1)$(NC)'
		@echo -e '$(ORANGE)$(H_2)$(NC)'
		@echo -e '$(GREEN)$(H_3)$(NC)'
		@echo -e '$(CYAN)$(H_4)$(NC)'
		@echo -e '$(L_BLUE)$(H_5)$(NC)'
		@echo -e '$(BLUE)$(H_6)$(NC)'
		@echo -e '$(PURPLE)$(H_7)$(NC)'
		@echo -ne '$(CYAN)'
else
		@echo -ne '$(H_1)\n$(H_2)\n$(H_3)\n$(H_4)\n$(H_5)\n$(H_6)\n$(H_7)\n'
endif
		@echo -e '\nThis Makefile was made by Thery Fouchter while he was bored.'
		@echo -e 'Here is a list of usefull functionalities and tips:'
ifneq ($(PIMP),)
		@echo -ne '$(L_BLUE)'
endif
		@echo -e '\n. Compilation:'
ifneq ($(PIMP),)
		@echo -ne '$(BLUE)'
endif
		@echo -ne ' \t-> Compilation is made with '
ifneq ($(PIMP),)
		@echo -e '$(CYAN)make$(BLUE) or $(CYAN)make re$(BLUE)'
else
		@echo -e 'make or make re'
endif
		@echo -e ' \t\t- Make compile only modified files whereas make re recompile all files'
		@echo -ne ' \t-> By Default the compilation is made with some '
ifneq ($(PIMP),)
		@echo -e '$(CYAN)flags$(BLUE),'
		@echo -e ' \t\t- $(CYAN)Disable$(BLUE) them with make $(CYAN)F=$(BLUE)'
		@echo -e ' \t\t- $(CYAN)Add$(BLUE) flags with make $(CYAN)FF=$(BLUE)"flags"'
		@echo -e ' \t-> The following variables will $(CYAN)change the compilation$(BLUE):'
		@echo -e ' \t\t- $(CYAN)NAME$(BLUE): Name of the binary'
		@echo -e ' \t\t- $(CYAN)INC$(BLUE): Folders for includes -I include'
		@echo -e ' \t\t- $(CYAN)LIB_1 / LIB_2$(BLUE): Libs used -Lfolder -llib'
		@echo -e ' \t\t  You can switch lib for LIB_2 with $(CYAN)L=2$(BLUE) variable (LIB_1 var by default)'
		@echo -e ' \t\t- $(CYAN)F$(BLUE): Flags used in compilation'
		@echo -e ' \t\t- $(CYAN)VG$(BLUE): Flags used when compiling with make valgrind or revalgrind'
		@echo -e ' \t-> $(CYAN)Be careful$(BLUE), if you change your $(CYAN).h$(BLUE) you need to $(CYAN)recompile$(BLUE) all files!'
else
		@echo -e 'flags,'
		@echo -e ' \t\t- Disable them with make F='
		@echo -e ' \t\t- Add flags with make FF="flags"'
		@echo -e ' \t-> The following variables will change the compilation:'
		@echo -e ' \t\t- NAME: Name of the binary'
		@echo -e ' \t\t- INC: Folders for includes -I include'
		@echo -e ' \t\t- LIB_1 / LIB_2: Libs used -Lfolder -llib'
		@echo -e ' \t\t  You can switch lib for LIB_2 with L=2 variable (LIB_1 var by default)'
		@echo -e ' \t\t- F: Flags used in compilation'
		@echo -e ' \t\t- VG: Flags used when compiling with make valgrind or revalgrind'
		@echo -e ' \t-> Be careful, if you change your .h you need to recompile all files!'
endif
ifneq ($(PIMP),)
		@echo -ne '$(L_BLUE)'
endif
		@echo -e '\n. Sources files:'
ifneq ($(PIMP),)
		@echo -e ' $(BLUE)\tYour $(CYAN)sources files$(BLUE) are located in $(CYAN)SRC$(BLUE) variable'
		@echo -e ' \tYour $(CYAN)main.c$(BLUE) file is located in $(CYAN)MAIN$(BLUE) variable '
		@echo -e ' \t(You can change your main with make MAIN=other.c for testing purposes.'
else
		@echo -e ' \tYour sources files are located in SRC variable'
		@echo -e ' \tYour main.c file is located in MAIN variable '
		@echo -e ' \t(You can change your main with make MAIN=other.c for testing purposes.'
endif
ifneq ($(PIMP),)
		@echo -ne '$(L_BLUE)'
endif
		@echo -e '\n. Tools:'
ifneq ($(PIMP),)
		@echo -e ' $(BLUE)\t-> make $(CYAN)clean$(BLUE): clean all tmp files, emacs tmp files and .o files'
		@echo -e ' \t-> make $(CYAN)fclean$(BLUE): do make clean and also remove your binary'
		@echo -e ' \t-> make $(CYAN)hclean$(BLUE): do make fclean and also remove make history file'
		@echo -e ' \t-> make $(CYAN)[x] OTHER=[x]$(BLUE): compile another makefile that is in OTHER= variable'
else
		@echo -e ' \t-> make clean: clean all tmp files, emacs tmp files and .o files'
		@echo -e ' \t-> make fclean: do make clean and also remove your binary'
		@echo -e ' \t-> make hclean: do make fclean and also remove make history file'
		@echo -e ' \t-> make [x] OTHER=[x]: compile another makefile that is in OTHER= variable'
endif
ifneq ($(PIMP),)
		@echo -ne '$(L_BLUE)'
endif
		@echo -e '\n. Run:'
ifneq ($(PIMP),)
		@echo -ne '$(BLUE) \t-> $(CYAN)Launch your binary$(BLUE) with make [X] '
		@echo -e '(X = $(CYAN)run, rerun, valgrind or revalgrind$(BLUE))'
		@echo -e ' \t   $(CYAN)Re$(BLUE), $(CYAN)Re$(BLUE)run and $(CYAN)re$(BLUE)valgrind $(CYAN)recompile$(BLUE) all your src files'
		@echo -e ' \t-> The following variables will change $(CYAN)how the binary is runned$(BLUE):'
		@echo -e ' \t\t- $(CYAN)ARGS$(BLUE)="arguments"'
		@echo -e ' \t\t- $(CYAN)IN$(BLUE)="arguments entered in stdin (via ECHO=-e by default)"'
		@echo -e ' \t\t- $(CYAN)P_IN$(BLUE)="program piped in stdin"'
		@echo -e ' \t\t- $(CYAN)IN_F$(BLUE)="file entered in stdin"'
		@echo -e ' \t\t- $(CYAN)OUT$(BLUE)="output redirected in file"'
		@echo -e ' \t\t- $(CYAN)P_OUT$(BLUE)="output piped in program"'
else
		@echo -ne ' \t-> Launch your binary with make [X] '
		@echo -e '(X = run, rerun, valgrind or revalgrind)'
		@echo -e ' \t   Re, Rerun and revalgrind recompile all your src files'
		@echo -e ' \t-> The following variables will change how the binary is runned:'
		@echo -e ' \t\t- ARGS="arguments"'
		@echo -e ' \t\t- IN="arguments entered in stdin (via ECHO=-e by default)"'
		@echo -e ' \t\t- P_IN="program piped in stdin"'
		@echo -e ' \t\t- IN_F="file entered in stdin"'
		@echo -e ' \t\t- OUT="output redirected in file"'
		@echo -e ' \t\t- P_OUT="output piped in program"'
endif
ifneq ($(PIMP),)
		@echo -ne '$(L_BLUE)'
endif
		@echo -e '\n. Display:'
ifneq ($(PIMP),)
		@echo -e ' $(BLUE)\t-> $(CYAN)Disable$(BLUE) colored display with the $(CYAN)PIMP=$(BLUE) variable'
		@echo -e ' \t   The value of this var also add a $(CYAN)custom message$(BLUE) when compiling'
		@echo -e ' \t-> The variable $(CYAN)BAR$(BLUE)=100 set the $(CYAN)percentage value$(BLUE) when compiling'
		@echo -e ' \t   This value can be changed and/or removed for removing percentage'
else
		@echo -e ' \t-> Disable colored display with the PIMP= variable'
		@echo -e ' \t   The value of this var also add a custom message when compiling'
		@echo -e ' \t-> The variable BAR=100 set the percentage value when compiling'
		@echo -e ' \t   This value can be changed and/or removed for removing percentage'
endif
ifneq ($(PIMP),)
		@echo -ne '$(L_BLUE)'
endif
		@echo -e '\n. History:'
ifneq ($(PIMP),)
		@echo -e '$(BLUE) \t-> $(CYAN)Keep track$(BLUE) on how many times you compiled your binary'
		@echo -e ' \t-> Can be disabled with HISTORY= variable'
		@echo -e ' \t-> The number of times compiled is $(CYAN)saved$(BLUE) in the file named by $(CYAN)HISTORY$(BLUE)=file'
		@echo -e ' \t-> You can remove this file by doing make hclean'
else
		@echo -e ' \t-> Keep track on how many times you compiled your binary'
		@echo -e ' \t-> Can be disabled with HISTORY= variable'
		@echo -e ' \t-> The number of times compiled is saved in the file named by HISTORY=file'
		@echo -e ' \t-> You can remove this file by doing make hclean'
endif

.PHONY:		all clean fclean hclean re run rerun valgrind revalgrind history help $(OTHER)
