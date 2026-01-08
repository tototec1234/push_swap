/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:32:14 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_one_stack(t_stack **a);

int	free_stacks_and_proc_state(t_stack *a, t_stack *b, t_proc *proc_state)
{
	if (a != NULL)
	{
		while (!a->next->is_sentinel)
			del_one_stack(&a);
		free(a);
		a = NULL;
	}
	if (b != NULL)
	{
		while (!b->next->is_sentinel)
			del_one_stack(&b);
		free(b);
		b = NULL;
	}
	if (proc_state != NULL)
	{
		clear_op_list(&proc_state->actual_op);
		clear_op_list(&proc_state->op_list);
		free(proc_state);
		proc_state = NULL;
	}
	return (SUCCESS);
}

t_proc	*init_proc_state(void)
{
	t_proc	*proc_state;

	proc_state = malloc(sizeof(t_proc));
	if (!proc_state)
		return (NULL);
	proc_state->op = INIT;
	proc_state->count = 0;
	proc_state->min_turn = 15;
	proc_state->limit_count = 15;
	proc_state->op_list = NULL;
	proc_state->actual_op = NULL;
	proc_state->sent_count_list = NULL;
	return (proc_state);
}

static void	del_one_stack(t_stack **a)
{
	t_stack	*current;

	current = (*a)->next;
	if (!current->is_sentinel)
	{
		(*a)->next = (*a)->next->next;
		free(current);
		current = NULL;
	}
}
