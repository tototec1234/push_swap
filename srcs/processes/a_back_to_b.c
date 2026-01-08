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

static void	del_one_trans_list(t_trans_list **sent_count_list);

int	proc_back_to_b(t_stack **a, t_stack **b, t_proc *proc_state)
{
	int	max_sorted_index;
	int	contnue;

	set_sorted_order_index_in_stack(*a);
	max_sorted_index = longest_soted_len(*a);
	while (proc_state->sent_count_list->transferred_to_a_count--)
	{
		if ((*a)->next->index == max_sorted_index)
		{
			contnue = cnt_elems_consecutive_target(max_sorted_index, *b);
			if ((*b)->next->index != max_sorted_index + contnue)
				execute_and_write(a, b, RR);
			else
				execute_and_write(a, b, RA);
			max_sorted_index++;
		}
		else
			execute_and_write(a, b, PB);
	}
	del_one_trans_list(&proc_state->sent_count_list);
	return (process_stack_b(*b, proc_state, SORT_START_THRESHOLD));
}

static void	del_one_trans_list(t_trans_list **sent_count_list)
{
	t_trans_list	*current;

	if (!sent_count_list || !*sent_count_list)
		return ;
	current = *sent_count_list;
	if ((*sent_count_list)->next)
	{
		*sent_count_list = (*sent_count_list)->next;
		free(current);
	}
	else
	{
		free(current);
		*sent_count_list = NULL;
	}
}
