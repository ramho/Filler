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

void 	init_struct(t_filler *f)
{
		f->map_x = 0;
		f->map_y = 0;
		f->piece_x = 0;
		f->piece_y = 0;
		f->count = 0;
		f->play_x = 0;
		f->play_y = 0;
}

int main()
{
  t_filler *f;
  char *buf;
  char **tab;
  int i = 0;
  int ret = 0;

  f = malloc(sizeof(*f));
  f->init = 0;
  get_player(f);

  tab = malloc(sizeof(char *) * 100);
  while((ret = get_next_line(0, &buf)) > 0)
  {
      if( f->init == 0)
          init_struct(f);
      if(ft_strstr(buf, "Plateau"))
      {
        get_map(f, buf);
      }
      if(ft_strstr(buf, "   "))
      {
        copy_map(f, buf);
        // FILE *ID = fopen("test.txt", "a");
        // fprintf(ID, "x %d y %d\n",f->play_x, f->play_y);
        // fclose(ID);
        ft_printf("%i %i\n", f->play_x, f->play_y);
      }
  }
  return(0);
}
