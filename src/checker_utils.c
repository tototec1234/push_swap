/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 03:46:39 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_instruction(const char *line, const char *instr);
static char	*add_char_to_str(char *str, char c, int len);

static int	compare_instruction(const char *line, const char *instr)
{
	size_t	instr_len;
	size_t	line_len;

	instr_len = ft_strlen(instr);
	line_len = ft_strlen(line);
	if (line_len != instr_len)
		return (0);
	return (ft_strncmp(line, instr, instr_len) == 0);
}

int	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (compare_instruction(line, "sa"))
		sa(a);
	else if (compare_instruction(line, "sb"))
		sb(b);
	else if (compare_instruction(line, "ss"))
		ss(a, b);
	else if (compare_instruction(line, "pa"))
		pa(a, b);
	else if (compare_instruction(line, "pb"))
		pb(a, b);
	else if (compare_instruction(line, "ra"))
		ra(a);
	else if (compare_instruction(line, "rb"))
		rb(b);
	else if (compare_instruction(line, "rr"))
		rr(a, b);
	else if (compare_instruction(line, "rra"))
		rra(a);
	else if (compare_instruction(line, "rrb"))
		rrb(b);
	else if (compare_instruction(line, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static char	*add_char_to_str(char *str, char c, int len)
{
	char	*new_str;
	int		i;

	new_str = malloc(len + 2);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

char	*ft_strjoin_char(char *str, char c)
{
	if (!str)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	return (add_char_to_str(str, c, ft_strlen(str)));
}

int	process_line(char *line, t_stack **a, t_stack **b)
{
	if (!execute_instruction(line, a, b))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
