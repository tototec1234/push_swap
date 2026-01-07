/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 03:46:57 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// stack_operations.c
t_stack	*create_node(int value);
void	stack_add_front(t_stack **stack, t_stack *new_node);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	clear_stack(t_stack **stack);

// instructions_swap.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// instructions_push.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// instructions_rotate.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// instructions_reverse_rotate.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// parse_utils.c
int		parse_args(int argc, char **argv, t_stack **a);
bool	is_sorted(t_stack *a);
bool	has_duplicates(t_stack *a);
bool	is_number(const char *str);

// checker_utils.c
int		execute_instruction(char *line, t_stack **a, t_stack **b);
char	*ft_strjoin_char(char *str, char c);
int		process_line(char *line, t_stack **a, t_stack **b);

// checker.c
int		read_instructions(t_stack **a, t_stack **b);

#endif
