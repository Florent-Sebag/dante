/*
** basic.c for h in /home/sebag/Bureau/dante/recup/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 14:47:46 2016 Florent Sebag
** Last update Sun May 22 23:22:25 2016 Dheilly Joss
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
