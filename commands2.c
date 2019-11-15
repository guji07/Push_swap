#include "push_swap.h"

void	ft_rb(t_stack *a, int flag)
{
	int 	c;

	if (flag)
		write(1, "rb\n", 3);
	if ((*a).size < 2)
		return ;
	c = (*a).array[0];
	ft_memmove((*a).array, ((*a).array) + 1, sizeof(int) * (*a).size - 1);
	(*a).array[(*a).size - 1] = c;
}

void	ft_rr(t_stack *a, t_stack *b, int flag)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (flag)
		write(1, "rr\n", 3);
}

void	ft_rra(t_stack *a, int flag)
{
	int 	c;

	if (flag)
		write(1, "rra\n", 4);
	c = (*a).array[(*a).size - 1];
	ft_memmove(((*a).array) + 1, ((*a).array), sizeof(int) * ((*a).size - 1));
	(*a).array[0] = c;
}

void	ft_rrb(t_stack *a, int flag)
{
	int 	c;

	if (flag)
		write(1, "rrb\n", 4);
	c = (*a).array[(*a).size - 1];
	ft_memmove(((*a).array) + 1, ((*a).array), sizeof(int) * ((*a).size - 1));
	(*a).array[0] = c;
}

void	ft_rrr(t_stack *a, t_stack *b, int flag)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}