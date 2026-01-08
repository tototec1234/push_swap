/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:51 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/08 23:59:51 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_stack_to_stack(t_stack **x, t_stack **y);

static int	push_stack_to_stack(t_stack **x, t_stack **y)
{
	t_stack	*a_nil;
	t_stack	*a_first;

	if ((*x)->next->is_sentinel)
		return (0);
	a_nil = *x;
	a_first = a_nil->next;
	a_first->next->prev = a_nil;
	a_nil->next = a_first->next;
	ft_addstack_front(y, &a_first);
	return (1);
}

int	push_a(t_stack **a, t_stack **b)
{
	return (push_stack_to_stack(b, a));
}

int	push_b(t_stack **a, t_stack **b)
{
	return (push_stack_to_stack(a, b));
}
