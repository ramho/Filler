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
}
