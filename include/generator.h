/*
** header.h for h in /home/sebag_f/Desktop/rendu/PSU_2015_minishell1
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
**
** Started on  Sun Jan 24 19:34:48 2016 Florent Sebag
** Last update Sun May 22 22:38:55 2016 Florent Sebag
*/

#ifndef HEADER_H_
# define HEADER_H_
# define READ_SIZE (50)

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct	s_elem
{
  struct s_elem	*prev;
  int		nb;
  int		x;
  int		y;
  struct s_elem	*next;
}		t_elem;

typedef struct	s_fir_end
{
  t_elem	*first;
  t_elem	*last;
  int		size;
}		t_fir_end;

int		add_case_end_int(t_fir_end *list, int nb, int x, int y);
int		create_list_int(t_fir_end *list, int nb, int x, int y);
void		init(t_fir_end *list);
t_fir_end	*create_linked(int **maze, int height, int width);
void		break_wall(int **maze, t_fir_end *list, int indic);
void		let_go_recu(int **maze, int x, int y, int val);
void		refresh_maze(int **maze, int x, int y, int val);
void		init(t_fir_end *list);
int		create_list_int(t_fir_end *list, int nb, int x, int y);
int		rm_case_list(t_fir_end *list, t_elem *elem);
int		add_case_end_int(t_fir_end *list, int nb, int x, int y);
t_fir_end	*create_linked(int **maze, int height, int width);
void		free_maze(int height, int **maze, t_fir_end *list);
void		create_maze(int width, int height, int indic);
void		print_int_tab(int **tab, int height, int width);

#endif /* !HEADER_H_ */
