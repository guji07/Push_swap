#include "push_swap.h"

void			try_solve(t_stack *a, int len)
{
	if (a->size == 1)
		ft_die("OK");
	if (a->size)
	{
		if (a->array[0] > a->array[1])
			ft_die("ra");
		else
			ft_die("Sorted");
	}
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
	try_solve(&a, len);
}

int 	main(int num, char **args)
{
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}