#include "filler.h"

int is_placable_piece(t_filler *f, int mx, int my)
{
	int x;
	int y;
	int my2;
	int tot;

	x = 0;
	y = 0;
	tot = 0;
	f->count = 0;
	while (x < f->piece_x)
	{
		my2 = my;
		y = 0;
		while (y < f->piece_y && my2 < f->map_y)
		{
			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 1)
				f->count += 1;
			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 2)
				return(0);
			if(f->count >= 2)
				return(0);
			y++;
			my2++;
			tot++;
		}
		x++;
		mx++;
	}
	if(f->count == 1 && tot == f->piece_tot) // je peux changer et mettre la limte dans le while de x
		return(1);
	return(0);
}



int	check_best_pos(t_filler *f, int p)
{
	int i;
	int j;
	int currentdiff;
	int smallestdiff;
	FILE *ID = fopen("test.txt", "a");

	i = 0;
	j = 0;
	smallestdiff = 1000;
	while(i < f->o && j < p)
	{
		currentdiff = abs(f->opp_piece[i] - f->all_pieces[j][2]);
		fprintf(ID, "current diff [%d] = %d - opp piece [%d] - my piece %d - [%d][%d]/%d - piece j [%d]\n", currentdiff, f->o, f->opp_piece[i] , p, f->all_pieces[j][0], f->all_pieces[j][1],f->all_pieces[j][2], j);
		if(currentdiff < smallestdiff)
		{
			smallestdiff = currentdiff;
			f->play_x = f->all_pieces[j][0];
			f->play_y = f->all_pieces[j][1];
		}
		if(f->opp_piece[i] < f->all_pieces[j][2])
			i++;
		else
			j++;
	}
	fprintf(ID, "piece [%d][%d]\n\n",f->play_x, f->play_y);
	fclose(ID);
	return(1);
}

int algo_3(t_filler *f)
{
		int x;
	int y;
	int i;

	x = 0;
	i = 0;
	f->all_pieces = malloc(sizeof(int*) * (f->map_x * f->map_y));
	while(x < (f->map_x - f->piece_x))
	{

		y = 0;
		while (y < f->map_y)
		{
			if(is_placable_piece(f,x,y) == 1)
			{
				f->all_pieces[i]=malloc(sizeof(int*) * 3);
				f->all_pieces[i][0] = x;
				f->all_pieces[i][1] = y;
				f->all_pieces[i][2] = x + y;
				// FILE *ID = fopen("test.txt", "a");
				// fprintf(ID, " placable piece [%d][%d] = [%d]\n", x,y, x+y);
				// fclose(ID);
				i++;
			}
			y++;
		}
		x++;
	}
	sort_int_dtab(f->all_pieces, i);
	return(check_best_pos(f, i));
}

int play(t_filler *f)
{
	// return(algo_3(f));
	if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 0)
			return(algo_go_south(f));
	// if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 1)
	// 		return(algo_go_north(f));
	// if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 1)
	// 	return(algo_sw_ne(f));
	// if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 1)
	// 		return(algo_3(f));
	if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 1)
		return(algo_ne_sw(f));




	if ((f->map_first_p >= (f->map_x + 1) / 2) && f->switch_algo == 0)
		return(algo_go_north(f));
	// if ((f->map_first_p >= (f->map_x + 1) / 2) && f->switch_algo == 1)
	// 		return(algo_go_south(f));
	// if ((f->map_first_p >= (f->map_x + 1) / 2) && f->switch_algo == 1)
	// 		return(algo_3(f));
	if ((f->map_first_p >= (f->map_x + 1) / 2) && f->switch_algo == 1)
		return(algo_sw_ne(f));
	return(error_handle(f));
}
