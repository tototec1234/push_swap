/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:07:33 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_under_6_rec(t_stack **a, t_stack **b, t_proc *proc_state, int rec_cnt);

int	sort_under_6_rec(t_stack **a, t_stack **b, t_proc *p_s, int rec_cnt)
{
	int	op_code;

	if (rec_cnt > p_s->limit_count)
		return (SUCCESS);
	if (((*b) == (*b)->next && is_sorted(*a)) && p_s->min_turn > rec_cnt)
	{
		p_s->min_turn = rec_cnt;
		return (updete_op_list(&p_s->actual_op, p_s, p_s->op_list));
	}
	op_code = SA;
	while (op_code++ < INIT)
	{
		if (!is_qualified(*a, *b, p_s, rec_cnt) || \
		!is_valid_op(*a, p_s, op_code - 1) || \
		!execute(a, b, op_code - 1))
			continue ;
		p_s->op = op_code - 1;
		if (add_operation(&p_s->op_list, op_code - 1) || \
		sort_under_6_rec(a, b, p_s, rec_cnt + 1))
			return (MALLOC_ERROR);
		execute_rev(a, b, op_code - 1);
		del_one_op(&p_s->op_list);
	}
	p_s->state = END;
	return (SUCCESS);
}

int	sort_under_6_elems(t_stack **a, t_stack **b, t_proc *proc_state)
{
	t_op_list		*current_node;

	if (sort_under_6_rec(a, b, proc_state, 0))
	{
		proc_state->state = END;
		return (MALLOC_ERROR);
	}
	current_node = proc_state->actual_op;
	while (current_node)
	{
		print_op(current_node->op);
		current_node = current_node->next;
	}
	proc_state->state = END;
	return (SUCCESS);
}
