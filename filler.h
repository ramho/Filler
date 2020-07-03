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
  int map_first_p;
  int first_p;

  int piece_x;
  int piece_y;
  int piece_tot;
  int **piece_tab;

  int play_x;
  int play_y;


  int count;
  int init;

}   t_filler;



int get_player(t_filler *f);

void get_map(t_filler *f, char *line);
int copy_map(t_filler *f);
void copy_map_bis(t_filler *f, int *i, char *line);

int		get_piece(t_filler *f, char *buf);
int copy_piece(t_filler *f);
void copy_piece_bis(t_filler *f, int *i, char *line);

int is_placable(t_filler *f);
int algo_go_north(t_filler *f);
int algo_go_south(t_filler *f);
int is_placable_piece(t_filler *f, int mx, int my);
int is_placable_bis(t_filler *f, int mx, int my, int x);

int get_digit(int *i, char *buf);
void 	init_struct(t_filler *f);

#endif
