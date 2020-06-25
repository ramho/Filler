#include "filler.h"

void get_player(t_filler *f)
{
  char *buf;

  get_next_line(0, &buf);
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
}

// when print, free all
//free gnl line

int main()
{
  t_filler *f;
  char *buf;
  char **tab;
  int i = 0;
  int ret = 0;

  f = malloc(sizeof(*f));
  get_player(f);
  f->init = 0;
  while((ret = get_next_line(0, &buf)) > 0)
  {
      if( f->init == 0)
          init_struct(f);
      if(ft_strstr(buf, "Plateau"))
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
