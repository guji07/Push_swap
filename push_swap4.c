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

int				ft_minimalnoe(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_oper			ft_init_oper(void)
{
	t_oper		oper;

	oper.ra = INT_MAX - 500;
	oper.rb = INT_MAX - 500;
	oper.rra = INT_MAX - 500;
	oper.rrb = INT_MAX - 500;
	oper.cas = 0;
	return (oper);
}

int				ft_cena(t_oper min)
{
	int		min1;
	int		min2;
	int		min3;
	int		min4;

	if ((min1 = min.ra + min.rb - ft_minimalnoe(min.ra, min.rb)) < 0)
		min1 = INT_MAX;
	if ((min2 = min.ra + min.rrb) < 0)
		min2 = INT_MAX;
	if ((min3 = min.rra + min.rb) < 0)
		min3 = INT_MAX;
	if ((min4 = min.rra + min.rrb - ft_minimalnoe(min.rra, min.rrb)) < 0)
		min4 = INT_MAX;
	if (min1 <= min2 && min1 <= min3 && min1 <= min4)
		return (min1);
	if (min2 <= min1 && min2 <= min3 && min3 <= min4)
		return (min2);
	if (min3 <= min1 && min3 <= min2 && min3 <= min4)
		return (min3);
	return (min4);
}

void			ft_kruti(t_stack *a, t_stack *b, t_oper oper)
{
	oper.cas = ft_oper_case(oper);
	if (oper.cas == 1)
		case1(a, b, oper);
	else if (oper.cas == 2)
		case2(a, b, oper);
	if (oper.cas == 3)
		case3(a, b, oper);
	if (oper.cas == 4)
		case4(a, b, oper);
}
