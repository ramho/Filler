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
  int border_piece; //check if piece reaches the very top(1) or bottom (2)

  int play_x;
  int play_y;

  int **all_pieces;
  int *opp_piece;
  int o;

  int count;
  int init;
  int switch_algo;

}   t_filler;



int get_player(t_filler *f);
int main(void);

void get_map(t_filler *f, char *line);
int copy_map(t_filler *f);
void copy_map_bis(t_filler *f, int *i, char *line);

int		get_piece(t_filler *f, char *buf);
int copy_piece(t_filler *f);
void copy_piece_bis(t_filler *f, int *i, char *line);

int play(t_filler *f);
int is_placable_piece(t_filler *f, int mx, int my);


int algo_se_nw(t_filler *f);
int algo_nw_se(t_filler *f);
int algo_sw_ne(t_filler *f);
int algo_ne_sw(t_filler *f);
int   algo_bottom_right(t_filler *f);
int   algo_top_left(t_filler *f);


int get_digit(int *i, char *buf);
void 	init_struct(t_filler *f);
void		free_tab(t_filler *f);
int	error_handle(t_filler *f);

#endif

/*
FILE *ID = fopen("test.txt", "a");
fprintf(ID, "\n");
fclose(ID);
  */


/*  if (((f->border_piece == 2 && x == f->map_x - f->piece_x) || count > f->map_x) && f->switch_algo == 0)
      f->switch_algo = 1;
  if (((f->border_piece == 2 && x == f->map_x - f->piece_x) || count > f->map_x) && f->switch_algo == 1)
    f->switch_algo = 2;


    if (((f->border_piece == 1 && x == 0) || count > f->map_x) && f->switch_algo == 0)
      f->switch_algo = 1;
    if (((f->border_piece == 1 && x == 0) || count > f->map_x) && f->switch_algo == 1)
      f->switch_algo = 2;


      int   algo_top_left(t_filler *f)
      {
        int x;
        int y;
        static int count = 0;
        FILE *ID = fopen("test.txt", "a");
        fprintf(ID, "in algo top right\n");
        fclose(ID);

        x = 0;
      	while(x < f->map_x)
      	{
      		y = f->map_y / 2;
      		while(y >= 0)
      		{
      			if(is_placable_piece(f, x, y) == 1)
      			{
      				f->play_x = x;
      				f->play_y = y;
      				count++;
      				return(1);
      			}
      			y--;
      		}
      		x++;
          if(x == ((f->map_x - f->piece_x) + 1))
            return(algo_se_nw(f));
      	}
      	return(algo_se_nw(f));

      }*/
