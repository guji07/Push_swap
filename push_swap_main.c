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

t_oper			ft_oper(void)
{
	t_oper		oper;

	oper.ra = INT_MAX - 500;
	oper.rb = INT_MAX - 500;
	oper.rra = INT_MAX - 500;
	oper.rrb = INT_MAX - 500;
	oper.cas = 0;
	return (oper);
}

int				ft_find_low_index(t_stack *a, int value)
{
	int		i;

	i = (int)a->size - 1;
	while (i >= 0)
	{
		if (a->array[i] > value && (i > 0) && a->array[i - 1] < value)
			return ((int)a->size - i);
		if (i == (int)a->size - 1)
			if (a->array[a->size - 1] < value && a->array[0] > value)
				return (0);
		i--;
	}
	return (a->size);
}

int 			ft_minimalnoe(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int 			ft_oper_case(t_oper min)
{
	int 	min1;
	int 	min2;
	int 	min3;
	int 	min4;

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

int				ft_cena(t_oper min)
{
	int 	min1;
	int 	min2;
	int 	min3;
	int 	min4;

	if ((min1 = min.ra + min.rb - ft_minimalnoe(min.ra, min.rb)) < 0)
		min1 = INT_MAX;
	if((min2 = min.ra + min.rrb) < 0)
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

void 			case1(t_stack *a, t_stack *b, t_oper oper)
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
		ft_rra(a,1);
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

void			ft_sort(t_stack *a, t_stack *b)
{
	int		i;
	t_oper	oper;
	t_oper	min_oper;
	//int 	gg;

	while (b->size != 0)
	{
		oper = ft_oper();
		min_oper = oper;
		i = 0;
		while (i < (int)(b->size / 2))
		{
			oper.rb = i;
			oper.ra = ft_find_index(a, b->array[i]);
			oper.rra = ft_find_low_index(a, b->array[i]);
			i++;
			if ((ft_minimalnoe(ft_cena(oper), ft_cena(min_oper))) == ft_cena(oper))
				min_oper = oper;
			oper = ft_oper();
		}
		while (i < (int)b->size)
		{
			oper.rrb = (int)b->size - i;
			oper.ra = ft_find_index(a, b->array[i]);
			oper.rra = ft_find_low_index(a, b->array[i]);
			if (ft_minimalnoe(ft_cena(oper), ft_cena(min_oper)) == ft_cena(oper))
				min_oper = oper;
			oper = ft_oper();
			i++;
		}
		ft_kruti(a, b, min_oper);
		/*for (int g = 0; g < a->size; g++)
			printf("%i: %i %i\n", g, a->array[g], b->array[g]);
		if (getchar() == 'a')
			gg = 0;*/
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
