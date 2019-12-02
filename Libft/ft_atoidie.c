/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoidie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:01:15 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/30 01:21:26 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int					ft_atoidie(const char *str)
{
	int							z;
	long long int				sum;

	z = 1;
	sum = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' ||
	*str == '\v' || *str == '\a' || *str == '\r')
		str++;
	if (*str == '-')
		z = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		sum = (sum * 10) + (*str - '0');
		if (sum < 0 && z < 0)
			ft_die("Error\n");
		if (sum < 0 && z == 1)
			ft_die("Error\n");
		if (sum > (!z ? INT_MAX : 2147483648))
			ft_die("Error\n");
		str++;
	}
	return (int)(z * sum);
}
