/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 17:48:32 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_bonus	*create_node_bonus(int value)
{
	t_stack_bonus	*new_node;

	new_node = malloc(sizeof(t_stack_bonus));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_front_bonus(t_stack_bonus **stack, t_stack_bonus *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

void	stack_add_back_bonus(t_stack_bonus **stack, t_stack_bonus *new_node)
{
	t_stack_bonus	*tmp;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	stack_size_bonus(t_stack_bonus *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	clear_stack_bonus(t_stack_bonus **stack)
{
	t_stack_bonus	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
