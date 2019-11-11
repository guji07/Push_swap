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

int				ft_max(t_stack *a)
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
	max = ft_max(a);
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
	if (a->size == 1)
		ft_die("OK");
	if (a->array[0] > a->array[1])
			ft_die("ra");
		else
			ft_die("Sorted");
}

void			try_solve(t_stack *a)
{
	if (a->size < 3)
		ft_malo(a);
	else if (a->size == 3)
		ft_three(a);
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
	ft_free_ar(arr);
	try_solve(&a);
}

int 	main(int num, char **args)
{
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}