/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 14:30:52 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_op(t_stack *a, t_proc *ms, int op)
{
	if (a->next->index < a->next->next->index && \
		(op == SA || op == SS || op == RA || op == RRA))
		return (ft_putstr_fd("", 2), 0);
	if ((ms->op == SA && (op == SA || op == SS || op == RA || op == RR)) \
		|| (ms->op == SB && (op == SB || op == SS || op == RB || op == RR)) \
		|| (ms->op == SS && (op == SS || op == SA || op == SB)) \
		|| (ms->op == PA && op == PB) || (ms->op == PB && op == PA) \
		|| (ms->op == RA && (op == RRA || op == RR)) \
		|| (ms->op == RB && (op == RRB || op == RR)) \
		|| (ms->op == RR && (op == RR || op == RA || op == RB)) \
		|| (ms->op == RRA && (op == RA || op == RRR)) \
		|| (ms->op == RRB && (op == RB || op == RRR)) \
		|| (ms->op == RRR && (op == RRR || op == RRA || op == RRB)))
		return (ft_putstr_fd("", 2), 0);
	return (1);
}

int	execute(t_stack **a, t_stack **b, int op)
{
	static t_operation	f[] = \
	{
		swap_a, push_b, rotate_a, reverse_rotate_a, swap_b, \
		push_a, swap_ab, rotate_b, \
		rotate_ab, reverse_rotate_b, reverse_rotate_ab
	};

	return (f[op](a, b));
}

int	execute_rev(t_stack **a, t_stack **b, int op)
{
	static t_operation	f[] = \
	{
		swap_a, push_a, reverse_rotate_a, rotate_a, swap_b, \
		push_b, swap_ab, reverse_rotate_b, \
		reverse_rotate_ab, rotate_b, rotate_ab
	};

	return (f[op](a, b));
}

int	is_qualified(t_stack *a, t_stack *b, t_proc *proc_state, int rec_cnt)
{
	if (ft_stacklen(b) + rec_cnt + get_min_pos(a) + 1 \
	>= proc_state->min_turn)
		return (0);
	return (1);
}

int	get_min_pos(t_stack *a)
{
	int		count;

	count = 1;
	a = a->next;
	while (a->index == 0)
	{
		count++;
		a = a->next;
	}
	return (count);
}
