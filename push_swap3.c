/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:39:32 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/15 19:39:33 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "push_swap.h"

int				ft_sredarp(t_stack *a)
{
	int		i;
	int		sum;

	i = -1;
	sum = 0;
	while (++i < (int)a->size)
		sum += a->array[i];
	return (sum / i);
}

int				ft_maximalnoe(t_stack *a)
{
	int		i;
	int		max;

	i = -1;
	max = a->array[0];
	while (++i < (int)a->size)
		if (a->array[i] > max)
			max = a->array[i];
	return (max);
}

int				ft_minimum(t_stack *a)
{
	int		i;
	int		min;

	i = -1;
	min = a->array[0];
	while (++i < (int)a->size)
		if (a->array[i] < min)
			min = a->array[i];
	return (min);
}

int				ft_whilenot(t_stack *a)
{
	int		i;

	i = -1;
	while (++i < (int)(a->size - 1))
		if (a->array[i] > a->array[i + 1])
			return (0);
	return (1);
}

void			ft_five(t_stack *a, t_stack *b)
{
	b->array = ft_intmalloc(2);
	b->size = 0;
	while (a->size != 3)
	{
		if (a->array[4] == ft_minimum(a))
			ft_rra(a, 1);
		if (a->array[0] != ft_minimum(a))
			ft_ra(a, 1);
		else
			ft_pb(a, b, 1);
	}
	ft_three(a);
	ft_pa(a, b, 1);
	ft_pa(a, b, 1);
}
