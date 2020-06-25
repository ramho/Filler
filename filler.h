#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>//
# include "libft/libft.h"


typedef struct s_filler
{
  // char p;
  char p1;
  char p2;

  int map_x;
  int map_y;
  int **map_tab;

  int piece_x;
  int piece_y;
  int piece_tot;
  int **piece_tab;

  int play_x;
  int play_y;


  int count;
  int init;

}   t_filler;



void get_player(t_filler *f);

void get_map(t_filler *f, char *line);
int copy_map(t_filler *f);

int		get_piece(t_filler *f, char *buf);
int copy_piece(t_filler *f);

int is_placable(t_filler *f);
int is_placable_piece(t_filler *f, int mx, int my);

int get_digit(int *i, char *buf);
void 	init_struct(t_filler *f);

#endif
