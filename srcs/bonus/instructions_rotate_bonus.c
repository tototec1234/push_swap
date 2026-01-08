/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 03:43:23 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_bonus(t_stack_bonus **a)
{
	t_stack_bonus	*tmp;
	t_stack_bonus	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	rb_bonus(t_stack_bonus **b)
{
	t_stack_bonus	*tmp;
	t_stack_bonus	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	rr_bonus(t_stack_bonus **a, t_stack_bonus **b)
{
	ra_bonus(a);
	rb_bonus(b);
}
