/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:10:00 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 20:37:50 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

// Bonus part
typedef struct s_stack_bonus
{
	int						value;
	struct s_stack_bonus	*next;
}	t_stack_bonus;

// stack_operations_bonus.c
t_stack_bonus	*create_node_bonus(int value);
void			stack_add_front_bonus(t_stack_bonus **stack, \
				t_stack_bonus *new_node);
void			stack_add_back_bonus(t_stack_bonus **stack, \
				t_stack_bonus *new_node);
int				stack_size_bonus(t_stack_bonus *stack);
void			clear_stack_bonus(t_stack_bonus **stack);

// instructions_swap_bonus.c
void			sa_bonus(t_stack_bonus **a);
void			sb_bonus(t_stack_bonus **b);
void			ss_bonus(t_stack_bonus **a, t_stack_bonus **b);

// instructions_push_bonus.c
void			pa_bonus(t_stack_bonus **a, t_stack_bonus **b);
void			pb_bonus(t_stack_bonus **a, t_stack_bonus **b);

// instructions_rotate_bonus.c
void			ra_bonus(t_stack_bonus **a);
void			rb_bonus(t_stack_bonus **b);
void			rr_bonus(t_stack_bonus **a, t_stack_bonus **b);

// instructions_reverse_rotate_bonus.c
void			rra_bonus(t_stack_bonus **a);
void			rrb_bonus(t_stack_bonus **b);
void			rrr_bonus(t_stack_bonus **a, t_stack_bonus **b);

// parse_utils_bonus.c
int				parse_args_bonus(int argc, char **argv, t_stack_bonus **a);
bool			is_sorted_bonus(t_stack_bonus *a);
bool			has_duplicates_bonus(t_stack_bonus *a);
bool			is_number_bonus(const char *str);

// checker_utils_bonus.c
int				execute_instruction_bonus(char *line, \
				t_stack_bonus **a, t_stack_bonus **b);
char			*ft_strjoin_char(char *str, char c);
int				process_line(char *line, t_stack_bonus **a, t_stack_bonus **b);

// checker_bonus.c
int				read_instructions_bonus(t_stack_bonus **a, t_stack_bonus **b);

#endif
