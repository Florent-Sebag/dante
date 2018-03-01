/*
** break_wall.c for h in /home/sebag/Bureau/dante/creation
**
** Made by Sebag
** Login   <sebag_f@epitech.net>
**
** Started on  Tue May 10 16:13:03 2016 Sebag
** Last update Sun May 29 19:29:54 2016 Florent Sebag
*/

#include "time.h"
#include "generator.h"

void		print_int_tab(int **tab, int height, int width)
{
  int		x;
  int		y;

  y = 0;
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  if (tab[y][x] >= 0)
	    printf("*");
	  else
	    printf("X");
	  x = x + 1;
	}
      if (y + 1 < height)
	printf("\n");
      y = y + 1;
    }
}

int		min_val(int top, int left, int right, int bot)
{
  int		ret;

  ret = 2000000;
  if (top < ret && top > 0)
    ret = top;
  if (left < ret && left > 0)
    ret = left;
  if (right < ret && right > 0)
    ret = right;
  if (bot < ret && bot > 0)
    ret = bot;
  if (ret != 2000000)
    return (ret);
  return (-1);
}

int		test_elem(t_elem *elem, int **maze, int indic)
{
  int		top;
  int		bot;
  int		right;
  int		left;

  top = maze[elem->y - 1][elem->x];
  right = maze[elem->y][elem->x + 1];
  left = maze[elem->y][elem->x - 1];
  bot = maze[elem->y + 1][elem->x];
  if (indic == 1 && rand() % 2 == 0)
    return (min_val(top, left, right, bot));
  if (top > 0 && (top == right || top == left))
    return (0);
  if (right > 0 && (right == bot || right == left))
    return (0);
  if (bot > 0 && (bot == left || bot == top))
    return (0);
  return (min_val(top, left, right, bot));
}

int		find_min_val(int **maze, int x, int y)
{
  int		ret;

  ret = 2000000;
  if (ret > maze[y - 1][x] && maze[y - 1][x] >= 0)
    ret = maze[y - 1][x];
  if (ret > maze[y][x + 1] && maze[y][x + 1] >= 0)
    ret = maze[y][x + 1];
  if (ret > maze[y + 1][x] && maze[y + 1][x] >= 0)
    ret = maze[y + 1][x];
  if (ret > maze[y][x - 1] && maze[y][x -1] >= 0)
    ret = maze[y][x - 1];
  if (ret >= 0 && ret != 2000000)
    return (ret);
  else
    return (-3);
}

void		break_wall(int **maze, t_fir_end *list, int indic)
{
  t_elem	*elem;
  int		i;
  int		ret;
  int		nb_elem;

  srand(time(NULL));
  elem = list->first;
  while (list->size > 0)
    {
      nb_elem = rand() % 4;
      i = 0;
      while (nb_elem == 0)
	nb_elem = rand() % 4;
      while (i < nb_elem)
	{
	  elem = elem->next;
	  i = i + 1;
	}
      if ((ret = (test_elem(elem, maze, indic))) > 0)
	{
	  maze[elem->y][elem->x] = ret;
	  refresh_maze(maze, elem->x, elem->y, ret);
	}
      rm_case_list(list, elem);
    }
}
