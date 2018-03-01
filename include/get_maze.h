/*
** recup.h for h in /home/sebag/Bureau/dante/recup/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 13:59:14 2016 Florent Sebag
** Last update Sun May 22 22:26:18 2016 Florent Sebag
*/

#ifndef GET_MAZE_H_
# define GET_MAZE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_elem
{
  struct s_elem	*prev;
  struct s_elem	**nei;
  int		indic;
  char		data;
  int		x;
  int		y;
  struct s_elem	*file_elem;
  struct s_elem	*next;
}		t_elem;

typedef struct	s_fir_end
{
  t_elem	*first;
  t_elem	*last;
  int		width;
  int		height;
  int		size;
}		t_fir_end;

t_fir_end	*get_maze(int fd);
void		print_res(t_fir_end *list);

#endif /* !GET_MAZE_H_ */
