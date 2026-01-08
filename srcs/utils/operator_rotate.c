/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:48:19 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/09 00:00:05 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack **x);

static int	rotate_stack(t_stack **x)
{
	t_stack	*nil;
	t_stack	*last;
	t_stack	*nil_next;
	t_stack	*nil_next_next;

	if ((*x)->next == (*x)->prev)
		return (0);
	last = ft_stacklast(*x);
	nil = *x;
	nil_next = nil->next;
	nil_next_next = nil_next->next;
	nil->next = nil_next_next;
	nil_next_next->prev = nil;
	nil->prev = nil_next;
	nil_next->next = nil;
	last->next = nil_next;
	nil_next->prev = last;
	return (1);
}

int	rotate_a(t_stack **a, t_stack **b)
{
	(void)b;
	return (rotate_stack(a));
}

int	rotate_b(t_stack **a, t_stack **b)
{
	(void)a;
	return (rotate_stack(b));
}

int	rotate_ab(t_stack **a, t_stack **b)
{
	return (rotate_stack(a) | rotate_stack(b));
}
