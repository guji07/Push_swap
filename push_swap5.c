/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:49:50 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/15 19:49:52 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_find_value(t_stack *a, int value)
{
	int		i;

	i = -1;
	while (++i < (int)a->size)
		if (a->array[i] == value)
			return (i);
	return (i);
}

void			ft_firstdo(t_stack *a, t_stack *b, int flag)
{
	int		mid;
	int		min;
	int		max;

	b->array = ft_intmalloc(a->size);
	b->size = 0;
	mid = ft_sredarp(a);
	min = ft_minimum(a);
	max = ft_maximalnoe(a);
	while (a->size != 3)
	{
		if (a->array[0] != min && a->array[0] != max)
		{
			ft_pb(a, b, 1);
			if (b->array[0] > mid)
				ft_rb(b, 1);
		}
		else
			ft_ra(a, 1);
		if (flag == 1)
			ft_stackprint(a, b);
	}
	ft_three(a);
}

int				ft_find_index(t_stack *a, int value)
{
	int		i;

	i = -1;
	while (++i < (int)a->size)
		if (a->array[i] < value &&
		(i + 2 > (int)a->size || a->array[i + 1] > value))
			return (i + 1);
	return (-1);
}

int				ft_find_low_index(t_stack *a, int value)
{
	int		i;

	i = (int)a->size - 1;
	while (i >= 0)
	{
		if (a->array[i] > value && (i > 0) && a->array[i - 1] < value)
			return ((int)a->size - i);
		if (i == (int)a->size - 1)
			if (a->array[a->size - 1] < value && a->array[0] > value)
				return (0);
		i--;
	}
	return (a->size);
}

void			try_solve(t_stack *a, int flag)
{
	t_stack		b;

	ft_check_int(a->array, a->size);
	if (ft_whilenot(a))
		exit(0);
	b.array = NULL;
	if (a->size < 3)
		ft_malo(a);
	else if (a->size == 3)
		ft_three(a);
	else if (a->size == 5)
		ft_five(a, &b);
	else
	{
		ft_firstdo(a, &b, flag);
		ft_sort(a, &b, flag);
	}
	if (b.array)
		free(b.array);
}
