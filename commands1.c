#include "push_swap.h"

void	ft_sa(t_stack *a, int flag)
{
	int		c;

	if (flag)
		write(1, "sa\n", 3);
	if ((*a).size > 1)
	{
		c = (*a).array[0];
		(*a).array[0] = (*a).array[1];
		(*a).array[1] = c;
	}
}

void	ft_sb(t_stack *a, int flag)
{
	int		c;

	if (flag)
		write(1, "sb\n", 3);
	if ((*a).size > 1)
	{
		c = (*a).array[0];
		(*a).array[0] = (*a).array[1];
		(*a).array[1] = c;
	}
}

void	ft_ss(t_stack *a, t_stack *b, int flag)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (flag)
		write(1, "ss\n", 3);
}

void	ft_pa(t_stack *a, t_stack *b, int flag)
{
	int		c;

	if (flag)
		write(1, "pa\n", 3);
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
}

void	ft_pb(t_stack *a, t_stack *b, int flag)
{
	int		c;

	if (flag)
		write(1, "pb\n", 3);
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
}
