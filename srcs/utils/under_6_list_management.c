/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:49:33 by toruinoue         #+#    #+#             */
/*   Updated: 2024/11/08 23:59:49 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	copy_op_list(t_proc *proc_state, t_op_list *list);

void	del_one_op(t_op_list **list)
{
	t_op_list	*current;
	t_op_list	*prev;

	prev = NULL;
	if (!*list)
		return ;
	current = *list;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*list = NULL;
	free(current);
}

int	updete_op_list(t_op_list **old, t_proc *proc_state, t_op_list *new)
{
	clear_op_list(old);
	return (copy_op_list(proc_state, new));
}

void	clear_op_list(t_op_list **list)
{
	if (!*list)
		return ;
	while (*list)
		del_one_op(list);
}

int	add_operation(t_op_list **list, int op)
{
	t_op_list	*new_node;
	t_op_list	*current;

	new_node = malloc(sizeof(t_op_list));
	if (new_node == NULL)
		return (MALLOC_ERROR);
	new_node->op = op;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (SUCCESS);
}

static int	copy_op_list(t_proc *proc_state, t_op_list *list)
{
	int	op;
	int	err_code;

	while (list)
	{
		op = list->op;
		err_code = add_operation(&proc_state->actual_op, op);
		if (err_code)
			break ;
		list = list->next;
	}
	clear_op_list(&list);
	return (SUCCESS);
}
