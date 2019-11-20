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

void			ft_firstdo(t_stack *a, t_stack *b)
{
	int		i;
	int		len;
	int		mid;
	int		min;
	int		max;

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
	int		i;

	i = -1;
	while (++i < (int)a->size)
		if (a->array[i] < value &&
			(i + 2 > (int)a->size || a->array[i + 1] > value))
			return (i);
	return (-1);
}
