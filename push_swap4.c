/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:39:23 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/15 19:39:25 by tgarkbit         ###   ########.fr       */
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
	int		i;

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
