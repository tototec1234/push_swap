/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:48:15 by toruinoue         #+#    #+#             */
/*   Updated: 2024/11/12 20:30:43 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_stack_b(t_stack *b, t_proc *proc_state, int border)
{
	if (proc_state->state == END)
		return (MALLOC_ERROR);
	if (ft_stacklen(b) >= border)
		proc_state->state = PARTITION_HALF_B;
	else
		proc_state->state = SORT_B;
	return (SUCCESS);
}

int	perform_post_sort_b(t_stack *a, t_proc *proc_state)
{
	if (is_sorted(a))
		proc_state->state = END;
	else if (proc_state->sent_count_list)
		proc_state->state = BACK_TO_B;
	else
		proc_state->state = PARTITION_HALF_A;
	return (SUCCESS);
}
