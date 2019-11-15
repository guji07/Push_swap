#include "push_swap.h"

void	ft_ra(t_stack *a, int flag)
{
	int		c;

	if ((*a).size < 2)
		return ;
	c = (*a).array[0];
	ft_memmove((*a).array, ((*a).array) + 1, sizeof(int) * (*a).size - 1);
	(*a).array[(*a).size - 1] = c;
	if (flag)
		write(1, "ra\n", 3);
}