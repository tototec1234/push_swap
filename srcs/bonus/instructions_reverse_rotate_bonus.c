/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 17:48:32 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_bonus(t_stack_bonus **a)
{
	t_stack_bonus	*tmp;
	t_stack_bonus	*last;
	t_stack_bonus	*prev;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb_bonus(t_stack_bonus **b)
{
	t_stack_bonus	*tmp;
	t_stack_bonus	*last;
	t_stack_bonus	*prev;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr_bonus(t_stack_bonus **a, t_stack_bonus **b)
{
	rra_bonus(a);
	rrb_bonus(b);
}
