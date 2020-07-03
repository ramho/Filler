#include "filler.h"

int is_placable_piece(t_filler *f, int mx, int my)
{
	int x;
	int y;
	int my2;
	int tot;
	FILE *ID = fopen("test.txt", "a");
	fprintf(ID,"place piece\n");
	fclose(ID);
	x = 0;
	y = 0;
	tot = 0;
	f->count = 0;
	while (x < f->piece_x)
	{
		ID = fopen("test.txt", "a");
		fprintf(ID,"while x [%d] < piecex [%d]\n", x, f->piece_x);
		fclose(ID);
			// if((tot = is_placable_bis(f, mx, my, x)) == 0)
			// 	return(0);
		my2 = my;
		y = 0;
		while (y < f->piece_y && my2 <= f->map_y)
		{
			ID = fopen("test.txt", "a");
			fprintf(ID,"while y [%d] < piecey [%d] && my2[%d] <= f->mapy [%d]\n", y, f->piece_y, my2, f->map_y);
			fclose(ID);
			// if(my2 <= (f->map_y - f->piece_y))
			// {
				if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 1)
					f->count += 1;
				if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 2)
					return(0);
				if(f->count >= 2)
					return(0);
				// y++;
				// my2++;
				// tot++;
			// }
			y++;
			my2++;
			tot++;
		}
		x++;
		mx++;
	}
	if(f->count == 1 && tot == f->piece_tot)
		return(1);
	return(0);
}

// int is_placable_bis(t_filler *f, int mx, int my, int x)
// {
// 	int y;
// 	int tot;
// 	printf("here\n");
// 	y = 0;
// 	tot = 0;
// 	while (y < f->piece_y && my <= f->map_y)
// 	{
// 		if(y <= (f->map_y - f->piece_y))
// 		{
// 			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my] == 1)
// 				f->count += 1;
// 			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my] == 2)
// 				return(0);
// 			if(f->count >= 2)
// 				return(0);
// 			y++;
// 			my++;
// 			tot++;
// 		}
// }
// return(tot);
// }

int algo_go_north(t_filler *f)
{
	int x;
	int y;
	FILE *ID = fopen("test.txt", "a");
	fprintf(ID,"in go north\n");
	fclose(ID);
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
				return(1);
			}
			y++;
		}
		x++;
		if(x == ((f->map_x - f->piece_x) + 1))
			return(0);
	}
	return(0);
}

int algo_go_south(t_filler *f)
{
	int x;
	int y;
	FILE *ID = fopen("test.txt", "a");
	fprintf(ID,"in go south\n");
	fclose(ID);
	x = f->map_x - f->piece_x;
	y = f->map_y - f->piece_y;
	while(x >= 0)
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
		x--;
	}
	return(0);
}


int is_placable(t_filler *f)
{
	FILE *ID = fopen("test.txt", "a");
	fprintf(ID,"in is placable\n");
	fclose(ID);
	if (f->map_first_p < (f->map_x + 1) / 2)
			return(algo_go_south(f));
	if (f->map_first_p >= (f->map_x + 1) / 2)
		return(algo_go_north(f));
	return(0);
}
