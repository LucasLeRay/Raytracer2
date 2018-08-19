##
## Makefile for emacs in /home/Olivier/CPool_Day10
##
## Made by Olivier Telouk
## Login   <Olivier@epitech.net>
##
## Started on  Mon Oct 17 12:34:10 2016 Olivier Telouk
## Last update Thu May 25 08:05:31 2017 Olivier Telouk
##

SRC	=	main.c				\
		utils.c				\
		send.c				\
		principal.c			\
		mate.c				\
		piece_init.c			\
		free.c				\
		board.c				\
		copy.c				\
		moves.c				\
		controls.c			\
		get_controls.c			\
		pawn.c				\
		king.c				\
		exec_move.c			\
		lib/my/my_putchar.c		\
		lib/my/my_putstr.c		\
		lib/my/my_put_nbr.c		\
		lib/my/my_getnbr.c		\
		lib/my/my_strlen.c		

OBJ	=	$(SRC:.c=.o)

NAME	=	echec

all:	$(NAME)

$(NAME): $(OBJ)
	 gcc -g3 -o $(NAME) $(SRC) -lm -lcsfml-graphics -lcsfml-window  -lc_graph_prog


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
