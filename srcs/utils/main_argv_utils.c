/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_argv_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:59 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 17:27:02 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_array_size(char **str);

char	**updeta_args(int *argc, char **argv)
{
	char	**argv_split;
	char	*argv_combined;
	char	*tmp;

	if (*argc == 1)
		return (NULL);
	if (*argc == 2)
	{
		argv_combined = ft_strjoin(argv[0], " ");
		tmp = argv_combined;
		argv_combined = ft_strjoin(argv_combined, argv[1]);
		if (tmp != NULL && argv_combined == NULL)
			free(tmp);
		argv_split = ft_split(argv_combined, ' ');
		if (argv_split != NULL)
			*argc = get_array_size(argv_split);
		free(tmp);
		free(argv_combined);
	}
	else
		argv_split = argv;
	return (argv_split);
}

int	free_char_array(char **argv_split, int argc, char **argv)
{
	int	i;

	if (argv_split == argv)
		return (SUCCESS);
	i = 0;
	while (i < argc)
	{
		free(argv_split[i]);
		i++;
	}
	free(argv_split);
	return (SUCCESS);
}

static size_t	get_array_size(char **str)
{
	size_t	array_size;

	array_size = 0;
	while (str[array_size])
		array_size++;
	return (array_size);
}
