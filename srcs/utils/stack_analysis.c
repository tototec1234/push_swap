/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:11:44 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(t_stack *a)
{
	int	count;

	count = 0;
	a = a->next;
	while (!a->is_sentinel)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	cnt_elems_consecutive_target(int target, t_stack *stack)
{
	int		elems_abv_target;
	t_stack	*crt_node;

	elems_abv_target = 0;
	crt_node = stack->next;
	while (!crt_node->is_sentinel)
	{
		if (crt_node->index == target + elems_abv_target + 1)
		{
			elems_abv_target++;
			crt_node = stack;
		}
		else if (crt_node->index != target + elems_abv_target)
			break ;
		crt_node = crt_node->next;
	}
	return (elems_abv_target);
}

void	set_sorted_order_index_in_stack(t_stack *stack)
{
	t_stack	*current_node;
	t_stack	*compare_target;
	int		rank;

	current_node = stack->next;
	while (!current_node->is_sentinel)
	{
		rank = 0;
		compare_target = stack->next;
		while (!compare_target->is_sentinel)
		{
			if (current_node->value > compare_target->value)
				rank++;
			compare_target = compare_target->next;
		}
		current_node->index = rank;
		current_node = current_node->next;
	}
}

int	is_sorted(t_stack *a)
{
	if (a->prev == a->next)
		return (SUCCESS);
	a = a->next;
	while (!a->next->is_sentinel)
	{
		if (!(a->value < a->next->value))
			return (SUCCESS);
		a = a->next;
	}
	return (SORTED);
}
