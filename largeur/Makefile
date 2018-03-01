##
## Makefile for mak in /home/sebag_f/Desktop/rendu/PSU_2015_my_ls
##
## Made by Florent Sebag
## Login   <sebag_f@epitech.net>
##
## Started on  Fri Nov 27 18:39:02 2015 Florent Sebag
## Last update Sun May 22 23:37:19 2016 Dheilly Joss
##

NAME	= solver

SRCS	=	./../get_maze/basic.c \
		./../get_maze/call_gnl_to_end.c \
		./../get_maze/find_nei.c \
		./../get_maze/gnl.c \
		./../get_maze/linked.c \
		./../get_maze/read_fich.c \
		./../get_maze/free_linked.c \
		./../profondeur/resolve_prof.c \
		resolve_larg.c \
		linked_elem.c \
		main.c

CC	=	gcc

CFLAGS	=	-W -Wextra -Wall -Werror -I./../include

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME):
	 $(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
