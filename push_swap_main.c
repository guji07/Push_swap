/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:39:49 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/20 09:34:30 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_costyl(char ***arr, char **str, int *i, t_stack *a)
{
	*arr = ft_strsplit(*str, ' ');
	ft_valid(*str);
	free(*str);
	*i = 0;
	while ((*arr)[*i])
		(*i)++;
	a->array = ft_intmalloc(*i);
	*i = -1;
}

static	void	ft_get_args(int num, char **args)
{
	char		*str;
	int			len;
	int			i;
	char		**arr;
	t_stack		a;

	len = 0;
	i = 0;
	while (++i != num)
		len += ft_strlen(args[i]) + 1;
	i = 0;
	if ((str = ft_memalloc(len + 1)))
		while (++i < num)
			ft_strcatspace(str, args[i]);
	else
		ft_die("Error\n");
	ft_costyl(&arr, &str, &i, &a);
	while (arr[++i])
		a.array[i] = ft_atoidie(arr[i]);
	ft_free_ar(i, arr);
	a.size = i;
	try_solve(&a);
	free(a.array);
}

int				ft_costyl2(int *i, t_stack *a, t_stack *b, int min)
{
	int		rb;
	int		ra;
	int		index;

	index = 0;
	while (*i < (int)b->size)
	{
		rb = *i;
		ra = ft_find_index(a, b->array[*i]) + 1;
		if (ra + rb <= min)
		{
			min = ra + rb;
			index = *i;
		}
		(*i)++;
	}
	return (index);
}

void			ft_sort(t_stack *a, t_stack *b)
{
	int		ra;
	int		rb;
	int		min;
	int		i;

	i = 0;
	while (b->size != 0)
	{
		i = (i > (int)b->size ? 0 : i);
		min = ft_find_index(a, b->array[0]) + 1;
		rb = ft_costyl2(&i, a, b, min);
		ra = ft_find_index(a, b->array[rb]) + 1;
		if (ra < (int)a->size / 2)
			ft_insert(a, b, ra, rb);
		else
			ft_low_insert(a, b, ra, rb);
	}
	while (!ft_whilenot(a))
	{
		if (ft_find_value(a, ft_minimum(a)) < (int)a->size / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}

int				main(int num, char **args)
{
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}
