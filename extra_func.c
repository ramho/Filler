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
		f->border_piece = 0;
}

void		free_tab(t_filler *f)
{
	if (f->map_tab != NULL)
		ft_memdel((void **)f->map_tab);
	if (f->piece_tab != NULL)
		ft_memdel((void **)f->piece_tab);
}

int	error_handle(t_filler *f)
{
	if (f->map_tab != NULL)
		ft_memdel((void **)f->map_tab);
	if (f->piece_tab != NULL)
		ft_memdel((void **)f->piece_tab);
			ft_memdel1((void*)f->opp_piece);
	if(f != NULL)
		ft_memdel1((void *)f);
	ft_printf("0 0\n");
	return (-1);
}
