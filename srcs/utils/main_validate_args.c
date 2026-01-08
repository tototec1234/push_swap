/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:11:44 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique_value(t_stack *a)
{
	t_stack	*current_node;
	t_stack	*compare_target;

	current_node = a->next;
	while (!current_node->is_sentinel)
	{
		compare_target = current_node->next;
		while (!compare_target->is_sentinel)
		{
			if (current_node->value == compare_target->value)
				return (DUPLICATED_VALUES);
			compare_target = compare_target->next;
		}
		current_node = current_node->next;
	}
	return (SUCCESS);
}

int	is_numeric_representation(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (NUMERIC_ERROR);
	return (0);
}
