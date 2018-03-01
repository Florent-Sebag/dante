/*
** find_nei.c for h in /home/sebag/Bureau/dante/recup/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 15:04:06 2016 Florent Sebag
** Last update Sat May 21 15:47:08 2016 Florent Sebag
*/

#include "get_maze.h"

void		find_nei_top(t_elem *elem)
{
  int		x;
  int		y;
  t_elem	*tmp;

  tmp = elem;
  if (elem->y == 0)
    {
      elem->nei[0] = NULL;
      return ;
    }
  y = elem->y - 1;
  x = elem->x;
  elem = elem->prev;
  while (elem->y != y)
    elem = elem->prev;
  while (elem->x != x)
    elem = elem->prev;
  tmp->nei[0] = elem;
}

void		find_nei_right(t_fir_end *list, t_elem *elem)
{
  if (elem->x == list->width - 1)
    elem->nei[1] = NULL;
  else
    elem->nei[1] = elem->next;
}

void		find_nei_bot(t_fir_end *list, t_elem *elem)
{
  int		x;
  int		y;
  t_elem	*tmp;

  tmp = elem;
  if (elem->y == list->height - 1)
    {
      elem->nei[2] = NULL;
      return ;
    }
  y = elem->y + 1;
  x = elem->x;
  elem = elem->next;
  while (elem->y != y)
    elem = elem->next;
  while (elem->x != x)
    elem = elem->next;
  tmp->nei[2] = elem;
}

void		find_nei_left(t_elem *elem)
{
  if (elem->x == 0)
    elem->nei[3] = NULL;
  else
    elem->nei[3] = elem->prev;
}
