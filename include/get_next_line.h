/*
** get_next_line.h for h in /home/sebag/Bureau/CPE_colle_semaine4/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Thu May 19 16:40:24 2016 Florent Sebag
** Last update Thu May 19 16:40:35 2016 Florent Sebag
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (1)

#endif /* !READ_SIZE */

typedef	struct	s_char_err
{
  int		err;
  char		c;
}		t_char_err;

typedef	struct	s_result
{
  t_char_err	x;
  char		*result;
  int		i;
}		t_result;

char		*get_next_line(const int fd);
t_result	new_gnl(t_result res, int i, int fd, int reset);
int		new_other_gnl(t_result res, int indic);
int		verif_return(int ret);
char		*re_alloc(char *src, int size);
int		test_size(int size);
t_char_err	get_next_char(const int fd, int reset);
int		test_char(t_result res, int indic);

#endif /* !GET_NEXT_LINE_H_ */
