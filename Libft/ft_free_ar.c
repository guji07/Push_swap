#include "libft.h"

void		ft_free_ar(int n, char **ar)
{
	int j;

	j = n;
	while (j >= 0)
	{
		free(ar[j]);
		j--;
	}
	free(ar);
	return ;
}