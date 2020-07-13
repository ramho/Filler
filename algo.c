#include "filler.h"

int algo_se_nw(t_filler *f) //go north
{
	int x;
	int y;
	FILE *ID;
	static int count = 0;

	x = 0;
	while(x < f->map_x)
	{
		y = 0;
		while(y < f->map_y)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				count++;
				if (((f->border_piece == 1 && x == 0) || count > f->map_x) && f->switch_algo == 0)
					f->switch_algo = 3;
				if (((f->border_piece == 1 && x == 0) || count > f->map_x) && f->switch_algo == 1)
					f->switch_algo = 2;
				return(1);
			}
			y++;
		}
		x++;
		if(x == ((f->map_x - f->piece_x) + 1))
			return(error_handle(f));
	}
	return(error_handle(f));
}

int algo_nw_se(t_filler *f) //go south
{
	int x;
	int y;
	static int count = 0;

	x = f->map_x - f->piece_x;
	while(x >= 0)
	{
		y = f->map_y - f->piece_y;
		while(y >= 0)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				count++;
				if (((f->border_piece == 2 && x == f->map_x - f->piece_x) || count > f->map_x) && f->switch_algo == 0)
					f->switch_algo = 1;
				if (((f->border_piece == 2 && x == f->map_x - f->piece_x) || count > f->map_x) && f->switch_algo == 3)
						f->switch_algo = 4;
				return(1);
			}
			y--;
		}
		x--;
	}
	return(error_handle(f));
}

int algo_sw_ne(t_filler *f)
{
	int x;
	int y;
	static int count = 0;

  x = f->map_x - f->piece_x;
	while(x >= 0)
	{
    y = 0;
		while(y < f->map_y)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				count++;
				if(count > f->map_x)
					f->switch_algo = 1;
        if(f->switch_algo == 1 && ( x == 0 || count > f->map_x))
          f->switch_algo = 2;
				return(1);
			}
			y++;
		}
		x--;
	}
  if(x < 0 && y >= f->map_y)
    return(algo_nw_se(f));
	return(error_handle(f));
}

int algo_ne_sw(t_filler *f) //nw_se
{
	int x;
	int y;

  x = 0;
	while(x < f->map_x)
	{
		y = f->map_y - f->piece_y;
		while(y >= 0)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				return(1);
			}
			y--;
		}
		x++;
    if(x == ((f->map_x - f->piece_x) + 1))
      return(error_handle(f));
	}
	return(error_handle(f));
}

int   algo_top_left(t_filler *f)
{
	int x;
	int y;

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
				return(1);
			}
			y--;
		}
		x++;
		if(x == ((f->map_x - f->piece_x) + 1))
			return(algo_ne_sw(f));
	}
	return(algo_ne_sw(f));
}

int   algo_bottom_right(t_filler *f)
{
  int x;
  int y;

  x = f->map_x - f->piece_x;
	while(x > 0)
	{
		y = f->map_y;
		while(y >= f->map_y / 2)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				return(1);
			}
			y--;
		}
		x--;
	}
	return(algo_se_nw(f));

}
