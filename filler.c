#include "filler.h"

int get_player(t_filler *f)
{
  char *buf;

  if(!(get_next_line(0, &buf)))
    return(-1);
  if(ft_strstr(buf, "p1"))
  {
    f->p1 = 'O';
    f->p2 = 'X';
  }
  else
  {
    f->p1 = 'X';
    f->p2 = 'O';
  }
  ft_strdel(&buf);
  return(0);
}

// when print, free all
//free gnl line

int main()
{
  t_filler *f;
  char *buf;
  char **tab;

  f = malloc(sizeof(*f));
  if(get_player(f) == -1)
    return(-1); //free f
  f->init = 0;
  f->first_p = 0;
  while((get_next_line(0, &buf)) > 0)
  {
      if( f->init == 0)
          init_struct(f);
      if(buf[0] == 'P' && buf[1] == 'l')
        get_map(f, buf);
      if(ft_strstr(buf,"   "))
      {
        copy_map(f);
        ft_printf("%i %i\n", f->play_x, f->play_y);
      }
      ft_strdel(&buf);
  }
  return(0);
}
