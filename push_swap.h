#ifndef PUSHSWAP_PUSH_SWAP_H
#define PUSHSWAP_PUSH_SWAP_H

#include <stdio.h>
#include "push_swap.h"
#include "Libft/libft.h"

typedef struct	s_stack {
	int		*array;
	size_t	size;
} 				t_stack;

void	ft_sa(t_stack *a);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrr(t_stack *a, t_stack *b);

#endif //PUSHSWAP_PUSH_SWAP_H
