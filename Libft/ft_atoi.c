/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:00:51 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
int					ft_atoi(const char *str)
{
	int						z;
	signed long long int				sum;

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
		str++;
	}
	if (sum > INT_MAX || sum < INT_MIN)
		ft_die("Error\n");
	return (int)(z * sum);
}
