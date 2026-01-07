#include "push_swap.h"

static int	compare_instruction(const char *line, const char *instr)
{
	int	i;

	i = 0;
	while (line[i] && instr[i] && line[i] == instr[i])
		i++;
	return (line[i] == '\0' && instr[i] == '\0');
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

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static char	*ft_strjoin_char(char *str, char c)
{
	char	*new_str;
	int		i;
	int		len;

	if (!str)
	{
		new_str = malloc(2);
		if (!new_str)
			return (NULL);
		new_str[0] = c;
		new_str[1] = '\0';
		return (new_str);
	}
	len = ft_strlen(str);
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

int	read_instructions(t_stack **a, t_stack **b)
{
	char	buffer[1];
	char	*line;
	ssize_t	read_bytes;

	line = NULL;
	while (1)
	{
		read_bytes = read(0, buffer, 1);
		if (read_bytes <= 0)
			break ;
		if (buffer[0] == '\n')
		{
			if (line && line[0] != '\0')
			{
				if (!execute_instruction(line, a, b))
				{
					free(line);
					return (0);
				}
				free(line);
				line = NULL;
			}
		}
		else
		{
			line = ft_strjoin_char(line, buffer[0]);
			if (!line)
				return (0);
		}
	}
	if (line)
		free(line);
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
	{
		ft_putstr_fd("Error\n", 2);
		clear_stack(&a);
		return (1);
	}
	if (!read_instructions(&a, &b))
	{
		ft_putstr_fd("Error\n", 2);
		clear_stack(&a);
		clear_stack(&b);
		return (1);
	}
	if (is_sorted(a) && stack_size(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

