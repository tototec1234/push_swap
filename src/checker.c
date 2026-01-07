/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:03:45 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 03:46:28 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_line_char(char **line, t_stack **a, t_stack **b);
static int	handle_error(t_stack **a, t_stack **b);

static int	read_line_char(char **line, t_stack **a, t_stack **b)
{
	char	buffer[1];
	ssize_t	read_bytes;

	read_bytes = read(0, buffer, 1);
	if (read_bytes <= 0)
		return (0);
	if (buffer[0] == '\n')
	{
		if (*line && (*line)[0] != '\0')
		{
			if (!process_line(*line, a, b))
				return (0);
			*line = NULL;
		}
	}
	else
	{
		*line = ft_strjoin_char(*line, buffer[0]);
		if (!*line)
			return (0);
	}
	return (1);
}

int	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;
	int		result;

	line = NULL;
	while (1)
	{
		result = read_line_char(&line, a, b);
		if (result == 0)
			break ;
	}
	if (line)
		free(line);
	return (1);
}

static int	handle_error(t_stack **a, t_stack **b)
{
	ft_putstr_fd("Error\n", 2);
	clear_stack(a);
	clear_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &a))
		return (handle_error(&a, NULL));
	if (!read_instructions(&a, &b))
		return (handle_error(&a, &b));
	if (is_sorted(a) && stack_size(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
