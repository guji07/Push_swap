#ifndef PUSHSWAP_PUSH_SWAP_H
#define PUSHSWAP_PUSH_SWAP_H

#include <stdio.h>
#include "push_swap.h"
#include "Libft/libft.h"

typedef struct	s_stack {
	int		*array;
	size_t	size;
} 				t_stack;

void	ft_sa(t_stack *a, int flag);
void	ft_sb(t_stack *a, int flag);
void	ft_ss(t_stack *a, t_stack *b, int flag);

void	ft_pa(t_stack *a, t_stack *b, int flag);
void	ft_pb(t_stack *a, t_stack *b, int flag);

void	ft_ra(t_stack *a, int flag);
void	ft_rb(t_stack *a, int flag);
void	ft_rr(t_stack *a, t_stack *b, int flag);

void	ft_rra(t_stack *a, int flag);
void	ft_rrb(t_stack *a, int flag);
void	ft_rrr(t_stack *a, t_stack *b, int flag);

int 	ft_whilenot(t_stack *a);
#endif //PUSHSWAP_PUSH_SWAP_H
