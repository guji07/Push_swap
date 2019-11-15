/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:10:03 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/15 18:10:12 by tgarkbit         ###   ########.fr       */
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
	ft_memmove((*a).array, ((*a).array) + 1, sizeof(int) * (*a).size - 1);
	(*a).array[(*a).size - 1] = c;
}
