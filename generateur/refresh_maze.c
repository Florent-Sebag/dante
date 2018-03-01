/*
** refresh_maze.c for h in /home/sebag/Bureau/dante/creation/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Wed May 11 18:42:43 2016 Florent Sebag
** Last update Sun May 29 19:55:53 2016 Dheilly Joss
*/

#include "generator.h"

void		let_go_recu(int **maze, int x, int y, int val)
{
  maze[y][x] = val;
  refresh_maze(maze, x, y, val);
}

void		refresh_maze(int **maze, int x, int y, int val)
{
  if (val < maze[y - 1][x])
    let_go_recu(maze, x, y - 1, val);
  if (val < maze[y][x + 1])
    let_go_recu(maze, x + 1, y, val);
  if (val < maze[y + 1][x])
    let_go_recu(maze, x, y + 1, val);
  if (val < maze[y][x - 1])
    let_go_recu(maze, x - 1, y, val);
}

void		free_maze(int height, int **maze, t_fir_end *list)
{
  int		i;

  i = 0;
  while (i < height)
    {
      free(maze[i]);
      i++;
    }
  free(list);
  free(maze);
}
