/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:09:11 by toruinoue         #+#    #+#             */
/*   Updated: 2024/11/12 20:07:09 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	back_unsoted_to_b(t_stack **a, t_stack **b, t_proc *proc_state, \
int pb_count);
static int	push_b_and_rotate(t_stack **a, t_stack **b, \
int unsorted_len, int sorted_len);

int	proc_partition_half_a(t_stack **a, t_stack **b, t_proc *proc_state)
{
	int	pb_count;
	int	unsorted_len;
	int	sorted_len;
	int	next_sequence_len;
	int	len_a;

	set_sorted_order_index_in_stack(*a);
	len_a = ft_stacklen(*a);
	sorted_len = longest_soted_len(*a);
	unsorted_len = len_a - sorted_len;
	if (unsorted_len < SORT_START_THRESHOLD)
		return (back_unsoted_to_b(a, b, proc_state, unsorted_len));
	pb_count = push_b_and_rotate(a, b, unsorted_len, sorted_len);
	while (pb_count++ < unsorted_len / 2 + unsorted_len % 2)
	{
		next_sequence_len = cnt_elems_consecutive_target(sorted_len, *b);
		if (!next_sequence_len && \
		get_current_pos(*b, sorted_len) > ft_stacklen(*b) / 2)
			execute_and_write(a, b, RRR);
		else
			execute_and_write(a, b, RRA);
	}
	return (process_stack_b(*b, proc_state, SORT_START_THRESHOLD));
}

static int	back_unsoted_to_b(t_stack **a, t_stack **b, \
t_proc *proc_state, int unsorted_len)
{
	int	contnue;
	int	sorted_len;

	sorted_len = longest_soted_len(*a);
	while (unsorted_len-- > 0)
	{
		if ((*a)->next->index == sorted_len)
		{
			contnue = cnt_elems_consecutive_target(sorted_len, *b);
			if ((*b)->next->index != sorted_len + contnue)
				execute_and_write(a, b, RR);
			else
				execute_and_write(a, b, RA);
			sorted_len++;
		}
		else
			execute_and_write(a, b, PB);
	}
	proc_state->state = SORT_B;
	return (SUCCESS);
}

static int	push_b_and_rotate(t_stack **a, t_stack **b, \
int unsorted_len, int sorted_len)
{
	t_stack	*current;
	int		index;
	int		contnue;
	int		remaining_unsorted_elements;

	index = (ft_stacklen(*a) + sorted_len) / 2;
	remaining_unsorted_elements = unsorted_len;
	current = (*a)->next;
	while (ft_stacklen(*b) != unsorted_len / 2)
	{
		if (current->index < index)
			execute_and_write(a, b, PB);
		else
		{
			contnue = cnt_elems_consecutive_target(sorted_len, *b);
			if (contnue && (*b)->next->index != sorted_len + contnue)
				execute_and_write(a, b, RR);
			else
				execute_and_write(a, b, RA);
		}
		current = (*a)->next;
		remaining_unsorted_elements--;
	}
	return (remaining_unsorted_elements);
}
