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

static int	sort_3_elements(t_stack *a);
static int	sort_4_elements(t_stack *a, t_stack *b);

int	sort_2_to_4_elemts(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size == 2 && (*a)->next->index == 1)
		return (ft_putendl_fd("sa", 1), SUCCESS);
	if (stack_size == 3)
		return (sort_3_elements(*a));
	if (stack_size == 4)
		return (sort_4_elements(*a, *b));
	return (UNEXPECTED_ERROR);
}

static int	sort_3_elements(t_stack *a)
{
	if (a->next->index == 2)
		execute_and_write(&a, NULL, RA);
	else if (a->next->next->index == 2)
		execute_and_write(&a, NULL, RRA);
	if (a->next->index > a->next->next->index)
		execute_and_write(&a, NULL, SA);
	return (SUCCESS);
}

static int	sort_4_elements(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = get_current_pos(a, 0) + 1;
	if (min_index > 4 / 2 + 1)
		while (a->next->index != 0)
			execute_and_write(&a, &b, RRA);
	else
		while (a->next->index != 0)
			execute_and_write(&a, &b, RA);
	if (is_sorted(a))
		return (SUCCESS);
	execute_and_write(&a, &b, PB);
	set_sorted_order_index_in_stack(a);
	sort_3_elements(a);
	execute_and_write(&a, &b, PA);
	return (SUCCESS);
}

// void	t_stack **a, t_stack **b, t_proc *proc_state)
// {
// 	if (is_sorted(*a) && ft_stacklen(*b) == 0)
// 	{
// 		proc_state->state = END;
// 		return ;
// 	}
// 	sort_4_elements(*a, *b);
// 	proc_state->state = END;
// 	perform_post_sort_b(*a, proc_state);
// }
