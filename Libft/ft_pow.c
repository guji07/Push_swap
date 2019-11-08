/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:14:36 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/01 14:48:04 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	double	ft_pow(long double num, int power)
{
	int		i;
	int		k;

	i = 0;
	k = num;
	if (power == 0)
		return (1);
	while (++i < power)
		num *= k;
	return (num);
}
