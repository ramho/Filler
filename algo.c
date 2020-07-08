#include "filler.h"

int algo_go_north(t_filler *f) //se_nw
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
				if(count > f->map_x)
					f->switch_algo = 1;
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

int algo_go_south(t_filler *f) //nw_se
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
				if(count > f->map_x)
					f->switch_algo = 1;
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
				return(1);
			}
			y++;
		}
		x--;
	}
	return(error_handle(f));
}

int algo_ne_sw(t_filler *f) //nw_se
{
	int x;
	int y;
	static int count = 0;

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
				count++;
				if(count > f->map_x)
					f->switch_algo = 1;
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
