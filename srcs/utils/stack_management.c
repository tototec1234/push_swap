/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/10 18:10:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->is_sentinel = 0;
	new->index = 0;
	new->next = new;
	new->prev = new;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (!stack->next->is_sentinel)
		stack = stack->next;
	return (stack);
}

void	ft_addstack_front(t_stack **stack, t_stack **new)
{
	t_stack	*first;
	t_stack	*nil;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = *new;
		(*new)->prev = (*new);
		(*new)->next = (*new);
		return ;
	}
	nil = *stack;
	first = (*stack)->next;
	nil->next = *new;
	(*new)->prev = nil;
	(*new)->next = first;
	first->prev = *new;
}

int	ft_addstack_back(t_stack **stack, t_stack **new)
{
	t_stack	*last;

	if (!stack || !new)
		return (UNEXPECTED_ERROR);
	if (!*stack)
	{
		*stack = *new;
		(*new)->prev = *new;
		(*new)->next = *new;
		return (SUCCESS);
	}
	last = ft_stacklast(*stack);
	if (!last)
		return (UNEXPECTED_ERROR);
	last->next = *new;
	(*new)->next = *stack;
	(*new)->prev = last;
	(*stack)->prev = *new;
	return (SUCCESS);
}
