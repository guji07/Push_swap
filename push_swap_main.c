/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:39:49 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/25 15:14:38 by tgarkbit         ###   ########.fr       */
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

void			ft_dokryt(t_stack *a)
{
	while (!ft_whilenot(a))
	{
		if (ft_find_value(a, ft_minimum(a)) < (int)a->size / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}

void			ft_sort(t_stack *a, t_stack *b)
{
	int		i;
	t_oper	oper;
	t_oper	min_oper;

	while (b->size != 0)
	{
		min_oper = ft_init_oper();
		i = 0;
		while (i < (int)b->size)
		{
			oper = ft_init_oper();
			oper.rb = i;
			oper.rrb = (int)b->size - i;
			oper.ra = ft_find_index(a, b->array[i]);
			oper.rra = ft_find_low_index(a, b->array[i++]);
			if (ft_minimalnoe(ft_cena(oper),
					ft_cena(min_oper)) == ft_cena(oper))
				min_oper = oper;
		}
		ft_kruti(a, b, min_oper);
	}
	ft_dokryt(a);
}

int				main(int num, char **args)
{
	if (num != 1)
		ft_get_args(num, args);
	return (0);
}
