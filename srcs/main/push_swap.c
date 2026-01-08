/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:59 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:05:05 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_process(t_stack **a, t_stack **b, t_proc *proc_state);
static int	push_swap(t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	char	**argv_split;
	t_stack	*a;
	t_stack	*b;
	int		err_code;

	if (argc_2_before(argv, argc))
		return (55);
	argv_split = updeta_args(&argc, argv);
	argc_2_check(argv_split, argc);
	if (argv_split == NULL)
		return (put_error_message_and_return(UNEXPECTED_ERROR));
	if (argc < 3)
		return (free_char_array(argv_split, argc, NULL), 8);
	err_code = set_sentinel_a_b(&a, &b);
	if (err_code == SUCCESS)
		err_code = load_stack_a_from_arguments(&a, argv_split);
	free_char_array(argv_split, argc, argv);
	if (err_code == SUCCESS)
		err_code = push_swap(&a, &b);
	if (err_code != SET_SENTINEL_ERROR)
		free_stacks_and_proc_state(a, b, NULL);
	if (err_code != SUCCESS)
		put_error_message_and_return(err_code);
	return (err_code);
}

static int	push_swap(t_stack **a, t_stack **b)
{
	t_proc	*proc_state;
	int		stack_size;
	int		err_code;

	set_sorted_order_index_in_stack(*a);
	err_code = is_sorted(*a);
	if (err_code)
		return (err_code);
	stack_size = ft_stacklen(*a);
	if (stack_size <= 4)
		return (sort_2_to_4_elemts(a, b, stack_size));
	proc_state = init_proc_state();
	if (!proc_state)
		return (put_error_message_and_return(PROCESS_STATUS_INIT_ERROR));
	if (stack_size <= 6)
		err_code = sort_under_6_elems(a, b, proc_state);
	else
		proc_state->state = PARTITION_INITIAL_HALF_A;
	while (proc_state->state != END)
		err_code = handle_process(a, b, proc_state);
	free_stacks_and_proc_state(NULL, NULL, proc_state);
	return (put_error_message_and_return(err_code));
}

static int	handle_process(t_stack **a, t_stack **b, t_proc *proc_state)
{
	static t_push_swap_process	f[5];

	print_proc_state(proc_state);
	f[0] = proc_partition_initial_half_a;
	f[1] = proc_partition_half_b;
	f[2] = proc_sort_b;
	f[3] = proc_back_to_b;
	f[4] = proc_partition_half_a;
	return (f[proc_state->state](a, b, proc_state));
}

/*
	__attribute__((destructor)) static void destructor()
{
    system("leaks -q push_swap");
}
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG 
// // ARG="3 2 1"; ./push_swap $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
ARG="2 1 3 6 4"; ./push_swap $ARG | ./checker $ARG
ARG="8 2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
ARG="8 2 1 3 6 5 4 7"; ./push_swap $ARG | ./checker $ARG
ARG="0 2 1 3 6 5 4 7 8"; ./push_swap $ARG | wc -l
ARG="0 2 1 3 6 5 4 7 8"; ./push_swap $ARG | ./checker $ARG
https://www.youtube.com/watch?app=desktop&v=WEzFrMHzDAI
https://github.com/o-reo/push_swap_visualizer
RES=`./push_swap 1 4 3 2`
https://docs.google.com/presentation/d/
1c2PU6ZST7uMwNHl6aAz2WsJ5QFf1J7JJsMkW0VSTXc8/edit#slide=id.gc7df47266a_0_297
tar zcvf push_swap.tar.gz
tar -zxvf 1112_2037push_swap.tar.gz
valgrind --leak-check=full ./push_swap 3 2 1
valgrind --leak-check=full ./push_swap 3 2 1 0 4 5
*/
