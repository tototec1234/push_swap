/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 17:48:32 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	execute_instruction_bonus(char *line, t_stack_bonus **a, t_stack_bonus **b)
{
	if (compare_instruction(line, "sa"))
		sa_bonus(a);
	else if (compare_instruction(line, "sb"))
		sb_bonus(b);
	else if (compare_instruction(line, "ss"))
		ss_bonus(a, b);
	else if (compare_instruction(line, "pa"))
		pa_bonus(a, b);
	else if (compare_instruction(line, "pb"))
		pb_bonus(a, b);
	else if (compare_instruction(line, "ra"))
		ra_bonus(a);
	else if (compare_instruction(line, "rb"))
		rb_bonus(b);
	else if (compare_instruction(line, "rr"))
		rr_bonus(a, b);
	else if (compare_instruction(line, "rra"))
		rra_bonus(a);
	else if (compare_instruction(line, "rrb"))
		rrb_bonus(b);
	else if (compare_instruction(line, "rrr"))
		rrr_bonus(a, b);
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

int	process_line(char *line, t_stack_bonus **a, t_stack_bonus **b)
{
	if (!execute_instruction_bonus(line, a, b))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
