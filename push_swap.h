/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:10:31 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/19 18:02:47 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# include <stdio.h>
# include "push_swap.h"
# include "Libft/libft.h"
# include <string.h>

typedef struct	s_stack {
	int			*array;
	size_t		size;
}				t_stack;

typedef	struct	s_oper {
	int 		ra;
	int 		rra;
	int 		rb;
	int 		rrb;
	int 		cas;
}				t_oper;

void			ft_sa(t_stack *a, int flag);
void			ft_sb(t_stack *a, int flag);
void			ft_ss(t_stack *a, t_stack *b, int flag);
void			ft_pa(t_stack *a, t_stack *b, int flag);
void			ft_pb(t_stack *a, t_stack *b, int flag);
void			ft_ra(t_stack *a, int flag);
void			ft_rb(t_stack *a, int flag);
void			ft_rr(t_stack *a, t_stack *b, int flag);
void			ft_rra(t_stack *a, int flag);
void			ft_rrb(t_stack *a, int flag);
void			ft_rrr(t_stack *a, t_stack *b, int flag);
int				ft_whilenot(t_stack *a);

void			ft_check_int(int a[], int size);
void			ft_valid(char *str);
int				ft_checkcmd(char *str);

int				ft_min(t_stack *a);
int				ft_bot(t_stack *a);
int				ft_maximum(t_stack *a);
void			ft_three(t_stack *a);
void			ft_malo(t_stack *a);

int				ft_sredarp(t_stack *a);
int				ft_maximalnoe(t_stack *a);
int				ft_minimum(t_stack *a);
void			ft_firstdo(t_stack *a, t_stack *b);
void			ft_sort(t_stack *a, t_stack *b);
void			ft_sorted(t_stack *a, int c);
void			try_solve(t_stack *a);
int				ft_find_index(t_stack *a, int value);
int				ft_find_value(t_stack *a, int value);
void			ft_insert(t_stack *a, t_stack *b, int ra, int rb);
int				ft_whilenot(t_stack *a);
void			ft_low_insert(t_stack *a, t_stack *b, int ra, int rb);
void			ft_five(t_stack *a, t_stack *b);
void			ft_costyl3(char ***arr, t_stack *a, int flag);
void			ft_stackprint(t_stack *a, t_stack *b, int size);
#endif
