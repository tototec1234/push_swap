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

int	longest_soted_len(t_stack *a)
{
	int	longest_sequence_len;
	int	current_sequence_len;

	longest_sequence_len = 0;
	current_sequence_len = 1;
	while (!a->next->is_sentinel)
	{
		if (a->index + 1 == a->next->index)
		{
			current_sequence_len++;
			if (current_sequence_len > longest_sequence_len)
				longest_sequence_len = current_sequence_len;
			a = a->next;
			continue ;
		}
		a = a->next;
		current_sequence_len = 1;
	}
	return (longest_sequence_len);
}
