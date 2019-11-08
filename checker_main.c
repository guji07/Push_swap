#include "push_swap.h"

int 	ft_checkcmd(char *str)//проверка команды
{
	if (ft_strequ(str, "sa"))
		return (1);
	if (ft_strequ(str, "sb"))
		return (2);
	if (ft_strequ(str, "ss"))
		return (3);
	if (ft_strequ(str, "pa"))
		return (4);
	if (ft_strequ(str, "pb"))
		return (5);
	if (ft_strequ(str, "ra"))
		return (6);
	if (ft_strequ(str, "rb"))
		return (7);
	if (ft_strequ(str, "rr"))
		return (8);
	if (ft_strequ(str, "rra"))
		return (9);
	if (ft_strequ(str, "rrb"))
		return (10);
	if (ft_strequ(str, "rrr"))
		return (11);
	return (0);
}

void	ft_makeinstructions(t_stack *a, t_stack *b, int cmd)
{
	if (cmd == 1)
		ft_sa(a);
	if (cmd == 2)
		ft_sa(b);
	if (cmd == 3)
		ft_ss(a, b);
	if (cmd == 4)
		ft_pa(a, b);
	if (cmd == 5)
		ft_pb(a, b);
	if (cmd == 6)
		ft_ra(a);
	if (cmd == 7)
		ft_ra(b);
	if (cmd == 8)
		ft_rr(a, b);
	if (cmd == 9)
		ft_rra(a);
	if (cmd == 10)
		ft_rra(b);
	if (cmd == 11)
		ft_rrr(a, b);
	for (int i = 0; i < 5; i++)
		printf("%i: %i   %i\n", i, (*a).array[i], (*b).array[i]);
}

void	ft_sorted(t_stack *a, int c)
{
	int 	i;

	i = -1;
	if (c != 0)
		ft_die("KO\n");
	while (++i < (int)(a->size - 1))
		if (a->array[i] > a->array[i + 1])
		{
			free(a->array);
			ft_die("KO\n");
		}
	ft_die("OK\n");
}

void	ft_checkinstructions(t_stack *a, int len)
{
	char	*str;
	int		cmd;
	t_stack b;

	b.array = ft_intmalloc(len);//создаем пустой стек Б
	b.size = 0;
	for (int i = 0; i < 5; i++)
		printf("%i: %i   %i\n", i, (*a).array[i], (b).array[i]);
	while (get_next_line(0, &str))
	{
		cmd = ft_checkcmd(str);
		if (!cmd)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		else
			ft_makeinstructions(a, &b, cmd);//выполняем очередную команду
		free(str);
	}
	ft_sorted(a, b.size);
}

void	ft_get_args(int num, char **args)
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
	ft_checkinstructions(&a, len);//функция приема инструкций
}

/*int		main(int num, char **args)
{
	printf("stack a: stack b:\n");
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}*/