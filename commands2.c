#include "push_swap.h"

void	ft_rb(t_stack *a, int flag)
{
	int 	c;

	if ((*a).size < 2)
		return ;
	c = (*a).array[0];
	ft_memmove((*a).array, ((*a).array) + 1, sizeof(int) * (*a).size - 1);
	(*a).array[(*a).size - 1] = c;
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b, int flag)
{
	ft_ra(a, flag);
	ft_rb(b, flag);
}

void	ft_rra(t_stack *a, int flag)
{
	int 	c;

	c = (*a).array[(*a).size - 1];
	ft_memmove(((*a).array) + 1, ((*a).array), sizeof(int) * ((*a).size - 1));
	(*a).array[0] = c;
	if (flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *a, int flag)
{
	int 	c;

	c = (*a).array[(*a).size - 1];
	ft_memmove(((*a).array) + 1, ((*a).array), sizeof(int) * ((*a).size - 1));
	(*a).array[0] = c;
	if (flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b, int flag)
{
	ft_rra(a, flag);
	ft_rrb(b, flag);
}