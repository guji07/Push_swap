/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:39:36 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/20 09:34:45 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if ((a->array[1] > a->array[0] && a->array[1] < a->array[2]) ||
		(a->array[1] < a->array[0] && a->array[1] > a->array[2]))
		return (a->array[1]);
	return (a->array[2]);
}

int				ft_maximum(t_stack *a)
{
	if (a->array[0] > a->array[2])
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
	max = ft_maximum(a);
	if (a->array[0] == bot && a->array[1] == min)
		ft_sa(a, 1);
	if (a->array[0] == max && a->array[1] == bot)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
	if (a->array[0] == max && a->array[1] == min)
		ft_ra(a, 1);
	if (a->array[0] == min && a->array[1] == max)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	if (a->array[0] == bot && a->array[1] == max)
		ft_rra(a, 1);
}

void			ft_malo(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			ft_die("ra\n");
	}
}
