#include "filler.h"

int get_digit(int *i, char *buf)
{
	int ret;
	ret = ft_atoi(buf + *i);
	while (ft_isdigit(buf[*i]))
		*i = *i + 1;
	return (ret);
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
		f->map_tab = NULL;
		f->piece_tab = NULL;
		f->all_pieces = NULL;
		f->opp_piece = NULL;
		f->o = 0;
}

void		free_tab(t_filler *f)
{
	if (f->map_tab != NULL)
		ft_memdel((void **)f->map_tab);
	if (f->piece_tab != NULL)
		ft_memdel((void **)f->piece_tab);
	if (f->all_pieces != NULL)
			ft_memdel((void**)f->all_pieces);
	if (f->opp_piece!= NULL)
		ft_memdel1((void*)f->opp_piece);
}
//
// int	printf_error(t_filler *f)
// {
// 	if(f != NULL)
// 		ft_memdel1((void *)f);
// 	ft_printf("0 0\n");
// 	return (-1);
// }

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i++ < size)
	{
		j = -1;
		while (++j < size - 1)
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
	}
}

void	sort_int_dtab(int **tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i++ < size)
	{
		j = -1;
		while (++j < size - 1)
			if (tab[j][2] > tab[j + 1][2])
				ft_swap(&tab[j][2], &tab[j + 1][2]);
	}
}

int	error_handle(t_filler *f)
{
	if (f->map_tab != NULL)
		ft_memdel((void **)f->map_tab);
	if (f->piece_tab != NULL)
		ft_memdel((void **)f->piece_tab);
	if (f->all_pieces != NULL)
		ft_memdel((void**)f->all_pieces);
	if (f->opp_piece!= NULL)
			ft_memdel1((void*)f->opp_piece);
	if(f != NULL)
		ft_memdel1((void *)f);
	ft_printf("0 0\n");
	return (-1);
}
