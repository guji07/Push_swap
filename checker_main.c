/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:40:35 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/30 00:06:00 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_checkinstructions(t_stack *a, int flag)
{
	char	*str;
	int		cmd;
	t_stack	b;
	int		size;

	ft_check_int(a->array, a->size);
	b.array = ft_intmalloc(a->size);
	b.size = 0;
	size = a->size;
	while (get_next_line(0, &str))
	{
		cmd = ft_checkcmd(str);
		if (!cmd)
			ft_die("Error\n");
		else
			ft_makeinstructions(a, &b, cmd);
		free(str);
		if (flag == 1)
			ft_stackprint(a, &b, size);
	}
	ft_sorted(a, b.size);
	free(b.array);
}

void	ft_costyl3(char ***arr, t_stack *a, int flag)
{
	int		i;

	i = 0;
	while (((*arr))[i])
		i++;
	a->array = ft_intmalloc(i);
	i = -1;
	while ((*arr)[++i])
		a->array[i] = ft_atoidie(((*arr))[i]);
	ft_free_ar(i, *arr);
	a->size = i;
	ft_checkinstructions(a, flag);
	free(a->array);
}

void	ft_get_args(int num, char **args, int flag)
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
			ft_strcatspace(str, args[i]);
	else
		ft_die("Error\n");
	ft_valid(str);
	arr = ft_strsplit(str, ' ');
	free(str);
	ft_costyl3(&arr, &a, flag);
}

int		main(int num, char **args)
{
	if (num > 1)
	{
		if (ft_strequ("-v", args[1]))
			ft_get_args(num - 1, args + 1, 1);
		else
			ft_get_args(num, args, 0);
	}
	if (num == 1)
		return (0);
}
