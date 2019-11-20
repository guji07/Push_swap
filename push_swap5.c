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

void			try_solve(t_stack *a)
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
		ft_firstdo(a, &b);
		ft_sort(a, &b);
	}
	if (b.array)
		free(b.array);
}
