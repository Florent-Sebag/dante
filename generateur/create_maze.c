/*
** create_maze.c for  in /home/sebag/Bureau/dante/creation/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Wed May 18 16:38:17 2016 Florent Sebag
** Last update Sun May 22 23:18:02 2016 Dheilly Joss
*/


#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int		find_nb(int **maze, int x, int y, int nb)
{
  if (y % 2 == 0 && x % 2 == 0)
    maze[y][x] = -2;
  else if ((y % 2 == 0 && x % 2 != 0) || (y % 2 != 0 && x % 2 == 0))
    maze[y][x] = -1;
  else
    {
      maze[y][x] = nb;
      nb = nb + 1;
    }
  return (nb);
}

void		fill_maze(int **maze, int width, int height)
{
  int		x;
  int		y;
  int		nb;

  x = 1;
  y = 1;
  nb = 1;
  while (y < height - 1)
    {
      while (x < width - 1)
	{
	  nb = find_nb(maze, x, y, nb);
	  x = x + 1;
	}
      x = 1;
      y = y + 1;
    }
}

void		init_result_maze(int **maze, int width, int height)
{
  maze[0][0] = 1;
  maze[0][1] = 1;
  maze[height - 1][width - 1] = 1;
  maze[height - 2][width - 1] = 1;
  if (height % 2 == 0)
    maze[height - 3][width - 1] = 1;
  if (width % 2 == 0)
    maze[height - 3][width - 1] = 1;
}

void		send_to_all(int **maze, int height, int width, int indic)
{
  t_fir_end	*list;

  fill_maze(maze, width, height);
  list = create_linked(maze, height, width);
  break_wall(maze, list, indic);
  init_result_maze(maze, width, height);
  print_int_tab(maze, height, width);
  free_maze(height, maze, list);
}

void		create_maze(int width, int height, int indic)
{
  int		**maze;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((maze = malloc(sizeof(int *) * (height + 1))) == NULL)
    return ;
  while (i < height)
    {
      if ((maze[i] = malloc(sizeof(int) * (width + 1))) == NULL)
	return ;
      while (j < width)
	{
	  maze[i][j] = -2;
	  j = j + 1;
	}
       j = 0;
       i = i + 1;
    }
  send_to_all(maze, height, width, indic);
}
