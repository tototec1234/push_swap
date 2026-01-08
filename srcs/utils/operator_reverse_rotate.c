/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:59 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/08 23:59:57 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack **x);

static int	reverse_rotate_stack(t_stack **x)
{
	t_stack	*nil;
	t_stack	*last;
	t_stack	*last_prev;
	t_stack	*nil_next;

	if ((*x)->next == (*x)->prev)
		return (0);
	nil = *x;
	last = ft_stacklast(*x);
	nil_next = nil->next;
	last_prev = last->prev;
	nil->next = last;
	last->prev = nil;
	nil->prev = last_prev;
	last_prev->next = nil;
	last->next = nil_next;
	nil_next->prev = last;
	return (1);
}

int	reverse_rotate_a(t_stack **a, t_stack **b)
{
	(void)b;
	return (reverse_rotate_stack(a));
}

int	reverse_rotate_b(t_stack **a, t_stack **b)
{
	(void)a;
	return (reverse_rotate_stack(b));
}

int	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	return (reverse_rotate_stack(a) | reverse_rotate_stack(b));
}
