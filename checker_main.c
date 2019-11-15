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
		ft_sa(a, 0);
	if (cmd == 2)
		ft_sa(b, 0);
	if (cmd == 3)
		ft_ss(a, b, 0);
	if (cmd == 4)
		ft_pa(a, b, 0);
	if (cmd == 5)
		ft_pb(a, b, 0);
	if (cmd == 6)
		ft_ra(a, 0);
	if (cmd == 7)
		ft_ra(b, 0);
	if (cmd == 8)
		ft_rr(a, b, 0);
	if (cmd == 9)
		ft_rra(a, 0);
	if (cmd == 10)
		ft_rra(b, 0);
	if (cmd == 11)
		ft_rrr(a, b, 0);
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

void	ft_check_int(int a[], int size)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				ft_die("Error\n");
			j++;
		}
		i++;
	}
}

void	ft_checkinstructions(t_stack *a)
{
	char	*str;
	int		cmd;
	t_stack b;

	ft_check_int(a->array, a->size);
	b.array = ft_intmalloc(a->size);//создаем пустой стек Б
	b.size = 0;
	while (get_next_line(0, &str))
	{
		cmd = ft_checkcmd(str);
		if (!cmd)
		{
			ft_die("Error\n");
		}
		else
			ft_makeinstructions(a, &b, cmd);//выполняем очередную команду
		free(str);
	}
	ft_sorted(a, b.size);
	free(b.array);
}

void	ft_valid(char *str)
{
	int 	i;
	int 	flag;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9') && str[i] != '-'))
			ft_die("Error\n");
		if (str[i] >= '0' && str[i] <= '9')
			flag = 1;
	}
	if (flag == 0)
		ft_die("Error\n");
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
		len += (int)ft_strlen(args[i]) + 1;
	i = 0;
	if ((str = ft_memalloc(len + 1)))
		while (++i < num)
			ft_strcatspace(str, args[i]);//загоняем все аргументы в одну строку
	else
		ft_die("Error\n");
	ft_valid(str);
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
	ft_checkinstructions(&a);//функция приема инструкций
	free(a.array);
}

int		main(int num, char **args)
{
	if (num > 1)
		ft_get_args(num, args);
	if (num == 1)
		return (0);
}