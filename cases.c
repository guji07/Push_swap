/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:00:38 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/29 23:00:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_oper_case(t_oper min)
{
	int		min1;
	int		min2;
	int		min3;
	int		min4;

	min1 = min.ra + min.rb - ft_minimalnoe(min.ra, min.rb);
	min2 = min.ra + min.rrb;
	min3 = min.rra + min.rb;
	min4 = min.rra + min.rrb - ft_minimalnoe(min.rra, min.rrb);
	if (min1 <= min2 && min1 <= min3 && min1 <= min4)
		return (1);
	if (min2 <= min1 && min2 <= min3 && min3 <= min4)
		return (2);
	if (min3 <= min1 && min3 <= min2 && min3 <= min4)
		return (3);
	return (4);
}

void			case1(t_stack *a, t_stack *b, t_oper oper)
{
	while (oper.ra && oper.rb)
	{
		oper.ra--;
		oper.rb--;
		ft_rr(a, b, 1);
	}
	while (oper.ra)
	{
		ft_ra(a, 1);
		oper.ra--;
	}
	while (oper.rb)
	{
		ft_rb(b, 1);
		oper.rb--;
	}
	ft_pa(a, b, 1);
}

void			case2(t_stack *a, t_stack *b, t_oper oper)
{
	while (oper.ra)
	{
		ft_ra(a, 1);
		oper.ra--;
	}
	while (oper.rrb)
	{
		ft_rrb(b, 1);
		oper.rrb--;
	}
	ft_pa(a, b, 1);
}

void			case3(t_stack *a, t_stack *b, t_oper oper)
{
	while (oper.rra)
	{
		oper.rra--;
		ft_rra(a, 1);
	}
	while (oper.rb)
	{
		oper.rb--;
		ft_rb(b, 1);
	}
	ft_pa(a, b, 1);
}

void			case4(t_stack *a, t_stack *b, t_oper oper)
{
	while (oper.rra && oper.rrb)
	{
		oper.rra--;
		oper.rrb--;
		ft_rrr(a, b, 1);
	}
	while (oper.rra)
	{
		ft_rra(a, 1);
		oper.rra--;
	}
	while (oper.rrb)
	{
		ft_rrb(b, 1);
		oper.rrb--;
	}
	ft_pa(a, b, 1);
}
