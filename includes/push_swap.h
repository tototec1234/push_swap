/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:08:03 by toruinoue         #+#    #+#             */
/*   Updated: 2026/01/08 18:05:26 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef SORT_START_THRESHOLD
#  define SORT_START_THRESHOLD 16
# endif

# include "libft.h"
# include <stdbool.h>

enum e_error_code
{
	SUCCESS = 0,
	SET_SENTINEL_ERROR = 1,
	ARGUMENTS_INVALID = 2,
	NUMERIC_ERROR = 3,
	ITOA_ERROR = 4,
	OUT_OF_RANGE = 5,
	DUPLICATED_VALUES = 6,
	LOAD_ERROR = 7,
	STACK_A_INIT_ERROR = 8,
	STACK_B_INIT_ERROR = 9,
	PROCESS_STATUS_INIT_ERROR = 10,
	PROCESS_STATUS_DESTROY_ERROR = 11,
	PROCESS_STATUS_STATE_ERROR = 12,
	PROCESS_STATUS_OP_ERROR = 13,
	PROCESS_STATUS_OP_LIST_ERROR = 14,
	MALLOC_ERROR = 15,
	UNEXPECTED_ERROR = 16,
	SORTED = 17
};

enum e_state_ps
{
	PARTITION_INITIAL_HALF_A = 0,
	PARTITION_HALF_B = 1,
	SORT_B = 2,
	BACK_TO_B = 3,
	PARTITION_HALF_A = 4,
	WRAP_SORT_UNDER_SIX_ELEMENTS = 5,
	END = 6
};

enum e_operation
{
	SA = 0,
	PB = 1,
	RA = 2,
	RRA = 3,
	SB = 4,
	PA = 5,
	SS = 6,
	RB = 7,
	RR = 8,
	RRB = 9,
	RRR = 10,
	INIT = 11
};

typedef struct s_stack
{
	int				value;
	int				is_sentinel;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_op_list
{
	enum e_operation	op;
	struct s_op_list	*next;
}	t_op_list;

typedef struct s_trans_list
{
	int					transferred_to_a_count;
	struct s_trans_list	*next;
}	t_trans_list;

typedef struct s_proc
{
	enum e_state_ps		state;
	enum e_operation	op;
	t_op_list			*actual_op;
	t_op_list			*op_list;
	t_trans_list		*sent_count_list;
	int					limit_count;
	int					count;
	int					min_turn;
}	t_proc;

typedef int		(*t_push_swap_process)(t_stack **, t_stack **, t_proc *);
typedef int		(*t_operation)(t_stack **, t_stack **);

int			argv_check(char **argv_split);
void		argc_2_check( char **argv_split, int argc);
int			argc_2_before( char **argv, int argc);
t_stack		*ft_stacknew(int value);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_addstack_front(t_stack **stack, t_stack **new);
int			ft_addstack_back(t_stack **stack, t_stack **new);
int			ft_stacklen(t_stack *a);
int			is_unique_value(t_stack *a);
int			get_median(t_stack *stack, int size);
void		set_sorted_order_index_in_stack(t_stack *stack);
void		print_op(int op);
void		print_op_to_error(int op);
void		print_op_to_error_endl(int op);
void		put_recursio_space(int rec_cnt);
int			execute_and_write(t_stack **a, t_stack **b, int op);
int			swap_a(t_stack **a, t_stack **b);
int			swap_b(t_stack **a, t_stack **b);
int			swap_ab(t_stack **a, t_stack **b);
int			push_a(t_stack **a, t_stack **b);
int			push_b(t_stack **a, t_stack **b);
int			rotate_a(t_stack **a, t_stack **b);
int			rotate_b(t_stack **a, t_stack **b);
int			rotate_ab(t_stack **a, t_stack **b);
int			reverse_rotate_a(t_stack **a, t_stack **b);
int			reverse_rotate_b(t_stack **a, t_stack **b);
int			reverse_rotate_ab(t_stack **a, t_stack **b);
char		**updeta_args(int *array_size_from_argc, char **argv);
int			set_sentinel_a_b(t_stack **stack_a, t_stack **stack_b);
int			load_stack_a_from_arguments(t_stack **stack_a, char **argv);
int			free_char_array(char **argv_split, int argc, char **argv);
int			proc_partition_initial_half_a(t_stack **a, t_stack **b, \
				t_proc *proc_state);
int			proc_partition_half_b(t_stack **a, t_stack **b, \
				t_proc *proc_state);
int			proc_sort_b(t_stack **a, t_stack **b, t_proc *proc_state);
int			proc_back_to_b(t_stack **a, t_stack **b, t_proc *proc_state);
int			proc_partition_half_a(t_stack **a, t_stack **b, \
				t_proc *proc_state);
int			proc_wrap_sort_under_6(t_stack **a, t_stack **b, \
				t_proc *proc_state);
int			get_current_pos(t_stack *b, int index);
int			sort_under_6_elems(t_stack **a, t_stack **b, \
				t_proc *proc_state);
int			updete_op_list(t_op_list **old, t_proc *proc_state, \
				t_op_list *new);
void		del_one_op(t_op_list **list);
int			add_operation(t_op_list **list, int op);
void		clear_op_list(t_op_list **list);
int			free_stacks_and_proc_state(t_stack *a, t_stack *b, \
				t_proc *proc_state);
int			get_min_pos(t_stack *a);
t_proc		*init_proc_state(void);
int			is_sorted(t_stack *a);
int			longest_soted_len(t_stack *a);
int			get_current_pos(t_stack *a, int index);
int			cnt_elems_consecutive_target(int start_index, t_stack *stacs);
void		print_proc_state(t_proc *proc_state);
size_t		print_stack(t_stack *stack);
int			put_error_message_and_return(int error_code);
int			process_stack_b(t_stack *b, t_proc *proc_state, int border);
int			perform_post_sort_b(t_stack *a, t_proc *proc_state);
int			is_valid_op(t_stack *a, t_proc *ms, int op);
int			is_valid_opexecute(t_stack *a, t_proc *ms, int op);
int			execute(t_stack **a, t_stack **b, int op);
int			execute_rev(t_stack **a, t_stack **b, int op);
int			is_qualified(t_stack *a, t_stack *b, t_proc *proc_state, \
				int recursion_count);
void		put_recursio_space(int recursion_count);
int			load_stack_b(t_stack **stack_a, char **argv);
int			sort_2_to_4_elemts(t_stack **a, t_stack **b, int stack_size);
int			is_numeric_representation(char *str);
int			is_unique_values(t_stack *a);

// Bonus part
typedef struct s_stack_bonus
{
	int						value;
	struct s_stack_bonus	*next;
}	t_stack_bonus;

// stack_operations_bonus.c
t_stack_bonus	*create_node_bonus(int value);
void		stack_add_front_bonus(t_stack_bonus **stack, \
	t_stack_bonus *new_node);
void		stack_add_back_bonus(t_stack_bonus **stack, \
	t_stack_bonus *new_node);
int			stack_size_bonus(t_stack_bonus *stack);
void		clear_stack_bonus(t_stack_bonus **stack);

// instructions_swap_bonus.c
void		sa_bonus(t_stack_bonus **a);
void		sb_bonus(t_stack_bonus **b);
void		ss_bonus(t_stack_bonus **a, t_stack_bonus **b);

// instructions_push_bonus.c
void		pa_bonus(t_stack_bonus **a, t_stack_bonus **b);
void		pb_bonus(t_stack_bonus **a, t_stack_bonus **b);

// instructions_rotate_bonus.c
void		ra_bonus(t_stack_bonus **a);
void		rb_bonus(t_stack_bonus **b);
void		rr_bonus(t_stack_bonus **a, t_stack_bonus **b);

// instructions_reverse_rotate_bonus.c
void		rra_bonus(t_stack_bonus **a);
void		rrb_bonus(t_stack_bonus **b);
void		rrr_bonus(t_stack_bonus **a, t_stack_bonus **b);

// parse_utils_bonus.c
int			parse_args_bonus(int argc, char **argv, t_stack_bonus **a);
bool		is_sorted_bonus(t_stack_bonus *a);
bool		has_duplicates_bonus(t_stack_bonus *a);
bool		is_number_bonus(const char *str);

// checker_utils_bonus.c
int			execute_instruction_bonus(char *line, \
	t_stack_bonus **a, t_stack_bonus **b);
char		*ft_strjoin_char(char *str, char c);
int			process_line(char *line, t_stack_bonus **a, t_stack_bonus **b);

// checker_bonus.c
int			read_instructions_bonus(t_stack_bonus **a, t_stack_bonus **b);
#endif
