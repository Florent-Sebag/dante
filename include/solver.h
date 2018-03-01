/*
** solver.h for h in /home/sebag/Bureau/dante/resolve/include/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sat May 21 15:05:16 2016 Florent Sebag
** Last update Sun May 22 23:07:14 2016 Florent Sebag
*/

#ifndef SOLVER_H_
# define SOLVER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_maze.h"

void		find_nei_top(t_elem *elem);
void		find_nei_right(t_fir_end *list, t_elem *elem);
void		find_nei_bot(t_fir_end *list, t_elem *elem);
void		find_nei_left(t_elem *elem);
void		init(t_fir_end *list);
int		create_list(t_fir_end *list, int x, int y, char data);
int		add_case_end(t_fir_end *list, int x, int y, char data);
void		print_linked(t_fir_end *list);
int		my_strlen(char *str);
int		resolve_larg(t_fir_end *list, t_elem *elem, t_fir_end *file);
void		init_larg(t_fir_end *list);
void		init_prof(t_fir_end *list);
int		create_list_elem(t_fir_end *list, t_elem *elem);
t_elem		*rm_first_elem(t_fir_end *list);
int		add_elem_end(t_fir_end *list, t_elem *data);
void		free_linked(t_fir_end *list);

#endif /* SOLVER_H_ */
