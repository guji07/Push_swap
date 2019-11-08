#include "libft.h"

void	ft_swapint(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
	return ;
}