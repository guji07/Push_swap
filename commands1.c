#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int		c;

	if ((*a).size > 1)
	{
		c = (*a).array[0];
		(*a).array[0] = (*a).array[1];
		(*a).array[1] = c;
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sa(b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	int 	c;

	if ((*a).size > 0)
	{
		c = (*a).array[0];
		ft_memmove((*b).array + 1, (*b).array, sizeof(int) * ((*b).size));
		(*b).array[0] = c;
		(*b).size++;
		ft_memmove((*a).array, (*a).array + 1, sizeof(int) * ((*a).size - 1));
		(*a).array[(*a).size - 1] = 0;
		(*a).size--;
	}
	return ;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	int 	c;

	if ((*b).size > 0)
	{
		c = (*b).array[0];
		ft_memmove((*a).array + 1, (*a).array, sizeof(int) * ((*a).size));
		(*a).array[0] = c;
		(*a).size++;
		ft_memmove((*b).array, (*b).array + 1, sizeof(int) * ((*b).size - 1));
		(*b).array[(*b).size - 1] = 0;
		(*b).size--;
	}
	return ;
}

void	ft_ra(t_stack *a)
{
	int 	c;

	if ((*a).size < 2)
		return ;
	c = (*a).array[0];
	ft_memmove((*a).array, ((*a).array) + 1, sizeof(int) * (*a).size - 1);
	(*a).array[(*a).size - 1] = c;
}