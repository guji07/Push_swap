#include "push_swap.h"

int				ft_min(t_stack *a)
{
	if (a->array[0] < a->array[1] && a->array[0] < a->array[2])
		return (a->array[0]);
	else if (a->array[1] < a->array[0] && a->array[1] < a->array[2])
		return (a->array[1]);
	return (a->array[2]);
}

int				ft_bot(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->array[0] < a->array[2])
		return (a->array[0]);
	if (a->array[1] > a->array[0] && a->array[1] < a->array[2])
		return (a->array[1]);
	return (a->array[2]);
}

int				ft_maximum(t_stack *a)
{
	if (a->array[0] > a->array[2] && a->array[0] > a->array[2])
		return (a->array[0]);
	if (a->array[1] > a->array[0] && a->array[1] > a->array[2])
		return (a->array[1]);
	return (a->array[2]);	
}	

void			ft_three(t_stack *a)
{
	int		min;
	int		bot;
	int		max;

	min = ft_min(a);
	bot = ft_bot(a);
	max = ft_maximum(a);
	if (a->array[0] == bot && a->array[1] == min)
		write(1, "sa\n", 3);
	if (a->array[0] == max && a->array[1] == bot)
		write(1, "sa\nrra\n", 7);
	if (a->array[0] == max && a->array[1] == min)
		write(1, "ra\n", 3);	
	if (a->array[0] == min && a->array[1] == max)
		write(1, "sa\nra\n", 6);
	if (a->array[0] == bot && a->array[1] == max)
		write(1, "rra\n", 4);
}

void			ft_malo(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			ft_die("ra");
	}
}

int 			ft_sredarp(t_stack *a)
{
	int 	i;
	int 	sum;

	i = -1;
	sum = 0;
	while (++i < (int)a->size)
		sum += a->array[i];
	return (sum/i);
}

int				ft_maximalnoe(t_stack *a)
{
	int 	i;
	int 	max;

	i = -1;
	max = a->array[0];
	while (++i < (int)a->size)
		if (a->array[i] > max)
			max = a->array[i];
	return (max);
}

int				ft_minimum(t_stack *a)
{
	int 	i;
	int 	min;

	i = -1;
	min = a->array[0];
	while (++i < (int)a->size)
		if (a->array[i] < min)
			min = a->array[i];
	return (min);
}

void			ft_firstdo(t_stack *a, t_stack *b)
{
	int 	i;
	int 	len;
	int 	mid;
	int 	min;
	int 	max;

	b->array = ft_intmalloc(a->size);
	b->size = 0;
	i = 0;
	len = a->size;
	mid = ft_sredarp(a);
	min = ft_minimum(a);
	max = ft_maximalnoe(a);
	while (i++ < len)
	{
		if (a->array[0] < mid && a->array[0] != min && a->array[0] != max)
		{
			ft_pb(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_ra(a);
			write(1, "ra\n", 3);
		}
	}
	while (a->size > 2)
	{
		if (a->array[0] != min && a->array[0] != max)
		{
			ft_pb(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_ra(a);
			write(1, "ra\n", 3);
		}
	}
}

int				ft_find_index(t_stack *a, int value)
{
	int 	i;

	i = -1;
	while (++i < (int)a->size)
		if (a->array[i] > value)
			return (i);
	return (i);
}

void			ft_sort(t_stack *a, t_stack *b)
{
	int 	num;
	int 	i;
	int 	trash;
	int 	index;

	while (b->size != 0)
	{
		i = 0;
		num = (i + ft_find_index(a, b->array[i]));
		index = 0;
		while (++i < (int)b->size)
		{
			trash = i;
			if (trash + ft_find_index(a, b->array[i]) < num)
				index = i;
		}
		if (index < (int)b->size / 2)
			while (--index > 0)
			{
				ft_ra(b);
				write(1, "rb\n", 3);
			}
		else
			while (++index < (int)b->size)
			{
				ft_rra(b);
				write(1, "rrb\n", 4);
			}
		i = ft_find_index(a, b->array[0]);
		if (i < (int)a->size / 2)
			while (i-- > 0)
			{
				ft_ra(a);
				write(1, "ra\n", 3);
			}
		else
			while (i++ < (int)a->size)
			{
				ft_rra(a);
				write(1, "rra\n", 4);
			}
		ft_pa(a, b);
		write(1, "pa\n", 3);
		if (ft_find_index(a, ft_minimum(a)) < (int)a->size / 2)
			while (!ft_whilenot(a))
			{
				ft_ra(a);
				write(1, "ra\n", 3);
			}
		else
			while (!ft_whilenot(a))
			{
				ft_rra(a);
				write(1, "rra\n", 4);
			}
	}
}

int				ft_whilenot(t_stack *a)
{
	int 	i;

	i = -1;
	while (++i < (int)(a->size - 1))
		if (a->array[i] > a->array[i + 1])
		{
			return (0);
		}
	return (1);
}

void			try_solve(t_stack *a)
{
	t_stack b;

	if (a->size < 3)
		ft_malo(a);
	else if (a->size == 3)
		ft_three(a);
	else
	{
		ft_firstdo(a, &b);
		ft_sort(a, &b);
	}
	/*for (int i = 0; i < 25; i++)
		printf("%i: %i %i\n", i, a->array[i], b.array[i]);*/
}

static	void	ft_get_args(int num, char **args)
{
	char		*str;
	int			len;
	int			i;
	char		**arr;
	t_stack		a;

	len = 0;
	i = 0;
	while (++i != num)
		len += ft_strlen(args[i]) + 1;
	i = 0;
	if ((str = ft_memalloc(len + 1)))
		while (++i < num)
			ft_strcatspace(str, args[i]);//загоняем все аргументы в одну строку
	else
	{
		write(1, "Error\n", 6);
		return ;
	}
	arr = ft_strsplit(str, ' ');//теперь каждую цифру в отдельный массив
	free(str);
	i = 0;
	while (arr[i])
		i++;
	a.array = ft_intmalloc(i);
	i = -1;
	while (arr[++i])
		a.array[i] = ft_atoi(arr[i]);//создаем стек А из аргументов
	a.size = i;
	try_solve(&a);
}

int 	main(int num, char **args)
{
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}