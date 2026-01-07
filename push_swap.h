#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Stack operations
t_stack	*create_node(int value);
void	stack_add_front(t_stack **stack, t_stack *new_node);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	clear_stack(t_stack **stack);

// Instructions
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Parsing and validation
int		parse_args(int argc, char **argv, t_stack **a);
bool	is_sorted(t_stack *a);
bool	has_duplicates(t_stack *a);
bool	is_number(const char *str);
long	ft_atol(const char *str);

// Checker functions
int		execute_instruction(char *line, t_stack **a, t_stack **b);
int		read_instructions(t_stack **a, t_stack **b);

#endif

