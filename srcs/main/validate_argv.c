/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:59 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:05:05 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argc_2_before( char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
		{
			ft_putendl_fd("Error", 2);
			return (55);
		}
	}
	return (SUCCESS);
}

void	argc_2_check(char **argv_split, int argc)
{
	if (argc == 2)
	{
		if (argv_check(argv_split) == 0)
			return ;
		ft_putendl_fd("Error", 2);
	}
}

int	argv_check( char **argv_split)
{
	long	num;
	int		i;

	i = 1;
	while (argv_split[i])
	{
		if (!is_numeric_representation(argv_split[i]))
			return (NUMERIC_ERROR);
		num = ft_atol(argv_split[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (OUT_OF_RANGE);
		i++;
	}
	return (SUCCESS);
}
