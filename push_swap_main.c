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
	if ((a->array[1] > a->array[0] && a->array[1] < a->array[2]) ||
		(a->array[1] < a->array[0] && a->array[1] > a->array[2]))
		return (a->array[1]);
	return (a->array[2]);
}

int				ft_maximum(t_stack *a)
{
	if (a->array[0] > a->array[2])
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
		ft_sa(a, 1);
	if (a->array[0] == max && a->array[1] == bot)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
	if (a->array[0] == max && a->array[1] == min)
		ft_ra(a, 1);
	if (a->array[0] == min && a->array[1] == max)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	if (a->array[0] == bot && a->array[1] == max)
		ft_rra(a, 1);
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
			ft_pb(a, b, 1);
		else if (a->array[0] != min && a->array[0] != max)
		{
			ft_pb(a, b, 1);
			ft_rb(b, 1);
		}
		else
			ft_ra(a, 1);
	}
}

int				ft_find_index(t_stack *a, int value)
{
	int 	i;

	i = -1;
	while (++i < (int)a->size)
		if (a->array[i] < value && (i + 2 > (int)a->size || a->array[i + 1] > value))
			return (i);
	return (-1);
}

int 			ft_find_value(t_stack *a, int value)
{
	int 	i;

	i = -1;
	while (++i < (int)a->size)
		if (a->array[i] == value)
			return (i);
	return (i);
}

void			ft_insert(t_stack *a, t_stack *b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		ft_rr(a, b, 1);
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		ft_ra(a, 1);
		ra--;
	}
	while (rb > 0)
	{
		ft_rb(b, 1);
		rb--;
	}
	ft_pa(a, b, 1);
	ft_rra(a, 1);
}

int				ft_whilenot(t_stack *a)
{
	int 	i;

	i = -1;
	while (++i < (int)(a->size - 1))
		if (a->array[i] > a->array[i + 1])
			return (0);
	return (1);
}

void			ft_low_insert(t_stack *a, t_stack *b, int ra, int rb)
{
	while (ra < (int)a->size)
	{
		ft_rra(a, 1);
		ra++;
	}
	while (rb > 0)
	{
		ft_rb(b, 1);
		rb--;
	}
	ft_pa(a, b, 1);
}

void			ft_sort(t_stack *a, t_stack *b)
{
	int 	ra;
	int 	rb;
	int 	min;
	int		index;
	int 	i;

	i = 0;
	while (b->size != 0)
	{
		if (i > (int)b->size)
			i = 0;
		index = 0;
		min = ft_find_index(a, b->array[0]) + 1;
		for (; i < (int)b->size; i++)
		{
			rb = i;
			ra = ft_find_index(a, b->array[i]) + 1;
			if (ra + rb <= min)
			{
				min = ra + rb;
				index = i;
			}
		}
		rb = index;
		ra = ft_find_index(a, b->array[index]) + 1;
		if (ra < (int)a->size / 2)
			ft_insert(a, b, ra, rb);
		else
			ft_low_insert(a, b, ra, rb);
	}
	while (!ft_whilenot(a))
	{
		if (ft_find_value(a, ft_minimum(a)) < (int)a->size / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}

void			try_solve(t_stack *a)
{
	t_stack		b;

	if (ft_whilenot(a))
		exit (0);
	b.array = NULL;
	if (a->size < 3)
		ft_malo(a);
	else if (a->size == 3)
		ft_three(a);
	else if (a->size == 5)
	{
		b.array = ft_intmalloc(2);
		b.size = 0;
		while (a->size != 3)
		{
			if (a->array[0] != ft_minimum(a))
				ft_ra(a, 1);
			else
				ft_pb(a, &b, 1);
		}
		ft_three(a);
		ft_pa(a, &b, 1);
		ft_pa(a, &b, 1);
	}
	else
	{
		ft_firstdo(a, &b);
		ft_sort(a, &b);
	}
	if (b.array)
		free(b.array);
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
	ft_free_ar(i, arr);
	a.size = i;
	try_solve(&a);
	free(a.array);
}

int 	main(int num, char **args)
{
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}