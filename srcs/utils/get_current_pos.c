/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:51 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:11:20 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_current_pos(t_stack *stack, int index)
{
	t_stack	*current;
	int		pos;

	current = stack->next;
	pos = 1;
	while (1)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
}
