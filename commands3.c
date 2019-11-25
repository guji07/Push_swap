/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:10:03 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/20 09:33:38 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int flag)
{
	int		c;

	if (flag)
		write(1, "ra\n", 3);
	if ((*a).size < 2)
		return ;
	c = (*a).array[0];
	ft_memmove((*a).array, ((*a).array) + 1, sizeof(int) * ((*a).size - 1));
	(*a).array[(*a).size - 1] = c;
}

void	ft_check_int(int a[], int size)
{
	int		i;
	int		j;

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

void	ft_valid(char *str)
{
	int		i;
	int		flag;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] != ' ' &&
		!(str[i] >= '0' && str[i] <= '9') && str[i] != '-'))
			ft_die("Error\n");
		if (str[i] >= '0' && str[i] <= '9')
			flag = 1;
	}
	if (flag == 0)
		ft_die("Error\n");
}

int		ft_checkcmd(char *str)
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

void	ft_sorted(t_stack *a, int c)
{
	int		i;

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
