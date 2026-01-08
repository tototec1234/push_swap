/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 17:48:32 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number_bonus(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	has_duplicates_bonus(t_stack_bonus *a)
{
	t_stack_bonus	*current;
	t_stack_bonus	*check;

	current = a;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}

bool	is_sorted_bonus(t_stack_bonus *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	parse_args_bonus(int argc, char **argv, t_stack_bonus **a)
{
	long			num;
	t_stack_bonus	*new_node;
	int				i;

	i = 1;
	while (i < argc)
	{
		if (!is_number_bonus(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		new_node = create_node_bonus((int)num);
		if (!new_node)
			return (0);
		stack_add_back_bonus(a, new_node);
		i++;
	}
	if (has_duplicates_bonus(*a))
		return (0);
	return (1);
}
