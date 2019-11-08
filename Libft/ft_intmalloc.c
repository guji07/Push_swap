#include "libft.h"

int 	*ft_intmalloc(int len)
{
	int *a;
	int i;

	a = (int*)malloc(len * sizeof(int));
	i = 0;
	while (i < len - 1)
		a[i++] = 0;
	return (a);
}