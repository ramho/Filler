#include "filler.h"

int get_digit(int *i, char *buf)
{
	int ret;
	ret=ft_atoi(buf + *i);
	while(ft_isdigit(buf[*i]))
		*i = *i + 1;
	return(ret);
}
