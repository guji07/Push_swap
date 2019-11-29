/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:58:48 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/20 09:33:51 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "push_swap.h"

void	ft_stackprint(t_stack *a, t_stack *b, int size)
{
	int		i;
	struct	timespec l;
	struct	timespec tr;

	l.tv_nsec = 90000000;
	l.tv_sec = 0;
	write(1, "\033[0;0f", 8);
	write(1, "\033[2J", 5);
	write(1, "Stack A: Stack B:\n", 18);
	i = -1;
	while (i++ < size - 2)
	{
		ft_printf(ANSI_COLOR_RED "%12i" ANSI_COLOR_RESET,
				i > (int)a->size ? 0 : (int)a->array[i]);
		ft_printf(ANSI_COLOR_GREEN " %12i\n" ANSI_COLOR_RESET,
				i > (int)b->size ? 0 : (int)b->array[i]);
	}
	ft_printf(ANSI_COLOR_RED "%12i" ANSI_COLOR_RESET,
			i > (int)a->size ? 0 : (int)a->array[i]);
	ft_printf(ANSI_COLOR_GREEN " %12i\n" ANSI_COLOR_RESET,
			i > (int)b->size ? 0 : (int)b->array[i]);
	nanosleep(&l, &tr);
}
