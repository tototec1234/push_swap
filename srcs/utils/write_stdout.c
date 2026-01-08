/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 17:57:21 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(int op)
{
	char	*stdput[12];

	stdput[0] = "sa";
	stdput[1] = "pb";
	stdput[2] = "ra";
	stdput[3] = "rra";
	stdput[4] = "sb";
	stdput[5] = "pa";
	stdput[6] = "ss";
	stdput[7] = "rb";
	stdput[8] = "rr";
	stdput[9] = "rrb";
	stdput[10] = "rrr";
	stdput[11] = "init";
	ft_putendl_fd(stdput[op], 1);
}

int	execute_and_write(t_stack **a, t_stack **b, int op)
{
	int					error;
	static t_operation	f[11];

	f[0] = swap_a;
	f[1] = push_b;
	f[2] = rotate_a;
	f[3] = reverse_rotate_a;
	f[4] = swap_b;
	f[5] = push_a;
	f[6] = swap_ab;
	f[7] = rotate_b;
	f[8] = rotate_ab;
	f[9] = reverse_rotate_b;
	f[10] = reverse_rotate_ab;
	print_op(op);
	print_op_to_error_endl(op);
	error = f[op](a, b);
	if (!error)
		exit(1);
	return (error);
}

// size_t	print_stack(t_stack *stack)
// {
// 	t_stack	*current;
// 	size_t	i;

// 	i = 0;
// 	current = stack->next;
// 	while (current->is_sentinel == 0)
// 	{
// 		ft_putnbr_fd(current->index, 2);
// 		ft_putstr_fd(" -> ", 2);
// 		current = current->next;
// 		i++;
// 	}
// 	ft_putendl_fd("", 2);
// 	return (i);
// }
