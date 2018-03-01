##
## Makefile for mak in /home/sebag_f/Desktop/rendu/PSU_2015_my_ls
##
## Made by Florent Sebag
## Login   <sebag_f@epitech.net>
##
## Started on  Fri Nov 27 18:39:02 2015 Florent Sebag
## Last update Sun May 22 23:36:53 2016 Dheilly Joss
##

NAME	=	generateur

SRCS	=	break_wall.c \
		create_maze.c \
		linked.c \
		main.c \
		refresh_maze.c

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
