#include "push_swap.h"

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_ra(b);
}

void	ft_rra(t_stack *a)
{
	int 	c;

	c = (*a).array[(*a).size - 1];
	ft_memmove(((*a).array) + 1, ((*a).array), sizeof(int) * ((*a).size - 1));
	(*a).array[0] = c;
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rra(b);
}