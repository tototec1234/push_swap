/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:09:11 by toruinoue         #+#    #+#             */
/*   Updated: 2024/11/12 19:52:51 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_pa_count_list(t_trans_list **sent_count_list, int pa_cout);

int	proc_partition_half_b(t_stack **a, t_stack **b, t_proc *proc_state)
{
	int			remaining_elements_to_push_a;
	int			pivot;
	int			pa_cout;
	t_stack		*top_element_b;

	set_sorted_order_index_in_stack(*b);
	remaining_elements_to_push_a = ft_stacklen(*b) / 2;
	pivot = remaining_elements_to_push_a - !(ft_stacklen(*b) % 2);
	pa_cout = 0;
	top_element_b = (*b)->next;
	while (remaining_elements_to_push_a > 0)
	{
		if (top_element_b->index > pivot)
		{
			pa_cout += execute_and_write(a, b, PA);
			--remaining_elements_to_push_a;
		}
		else
			execute_and_write(a, b, RB);
		top_element_b = (*b)->next;
	}
	if (add_pa_count_list(&proc_state->sent_count_list, pa_cout))
		proc_state->state = END;
	return (process_stack_b(*b, proc_state, SORT_START_THRESHOLD));
}

static int	add_pa_count_list(t_trans_list **sent_count_list, int pa_cout)
{
	t_trans_list	*new_node;

	new_node = malloc(sizeof(t_trans_list));
	if (!new_node)
		return (MALLOC_ERROR);
	new_node->transferred_to_a_count = pa_cout;
	new_node->next = NULL;
	if (!*sent_count_list)
		*sent_count_list = new_node;
	else
	{
		new_node->next = *sent_count_list;
		*sent_count_list = new_node;
	}
	return (SUCCESS);
}
