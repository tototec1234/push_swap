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

int	proc_partition_initial_half_a(t_stack **a, t_stack **b, t_proc *proc_state)
{
	int		pb_count;
	int		len_a;
	int		pivot_of_a;
	t_stack	*top_element_a;
	int		pivot_of_b;

	len_a = ft_stacklen(*a);
	pivot_of_a = len_a / 2 + len_a % 2;
	pivot_of_b = len_a / 4;
	pb_count = pivot_of_a;
	top_element_a = (*a)->next;
	set_sorted_order_index_in_stack(*a);
	while (pb_count > 0)
	{
		if (top_element_a->index < pivot_of_a)
			pb_count -= execute_and_write(a, b, PB);
		else if ((*b)->next->index < pivot_of_b)
			execute_and_write(a, b, RR);
		else
			execute_and_write(a, b, RA);
		top_element_a = (*a)->next;
	}
	return (process_stack_b(*b, proc_state, SORT_START_THRESHOLD));
}
