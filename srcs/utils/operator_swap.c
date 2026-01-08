/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:51 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/09 00:00:07 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack **x);

static int	swap_stack(t_stack **x)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if ((*x)->next == (*x)->prev)
		return (0);
	first = (*x)->next;
	second = first->next;
	third = second->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	if (!third->is_sentinel)
	{
		first->next = third;
		third->prev = first;
	}
	else
	{
		first->next = second->prev;
		second->prev->prev = first;
	}
	return (1);
}

int	swap_a(t_stack **a, t_stack **b)
{
	(void)b;
	return (swap_stack(a));
}

int	swap_b(t_stack **a, t_stack **b)
{
	(void)a;
	return (swap_stack(b));
}

int	swap_ab(t_stack **a, t_stack **b)
{
	return (swap_stack(a) | swap_stack(b));
}
