/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:18 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 20:12:24 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op_to_error_endl(int op)
{
	char	*stdput[12];

	(void)op;
	return ;
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
	ft_putendl_fd(stdput[op], 2);
}

void	print_op_to_error(int op)
{
	char	*stdput[12];

	(void)op;
	return ;
	stdput[0] = " sa";
	stdput[1] = " pb";
	stdput[2] = " ra";
	stdput[3] = " rra";
	stdput[4] = " sb";
	stdput[5] = " pa";
	stdput[6] = " ss";
	stdput[7] = " rb";
	stdput[8] = " rr";
	stdput[9] = " rrb";
	stdput[10] = " rrr";
	stdput[11] = " init";
	ft_putstr_fd(stdput[op], 2);
}

int	put_error_message_and_return(int error_code)
{
	char	*error_message[18];

	error_message[0] = "";
	error_message[1] = "Error: set_sentinel";
	error_message[2] = "Error\n";
	error_message[3] = "Error\n";
	error_message[4] = "Error\n";
	error_message[5] = "Error\n";
	error_message[6] = "Error\n";
	error_message[6] = "Error\n";
	error_message[7] = "Error: load error";
	error_message[8] = "";
	error_message[9] = "------------------";
	error_message[10] = "Error: process status init error";
	error_message[11] = "Error: process status destroy error";
	error_message[12] = "Error: process status state error";
	error_message[13] = "Error: process status op error";
	error_message[14] = "Error: process status op list error";
	error_message[15] = "Error: malloc error";
	error_message[16] = "";
	error_message[17] = "";
	ft_putstr_fd(error_message[error_code], 2);
	return (error_code);
}

void	print_proc_state(t_proc *proc_state)
{
	char	*status_name[7];

	(void)proc_state;
	return ;
	status_name[0] = "proc_partition_initial_half_a";
	status_name[1] = "proc_partition_half_b";
	status_name[2] = "proc_sort_b";
	status_name[3] = "proc_back_to_b";
	status_name[4] = "proc_partition_half_a";
	status_name[5] = "proc_wrap_sort_under_6";
	status_name[6] = "end";
	ft_putendl_fd(status_name[proc_state->state], 2);
}

/*
int	put_error_message_and_return(int error_code)
{
	char	*error_message[18];

	error_message[0] = "Error: no error";
	error_message[1] = "Error: set_sentinel";
	error_message[2] = "Error: invalid argments";
	error_message[3] = "Error: numeric error";
	error_message[4] = "Error: itoa error";
	error_message[5] = "Error: out of range";
	error_message[6] = "Error: duplicated values";
	error_message[7] = "Error: load error";
	error_message[8] = "Error: stack A init error";
	error_message[9] = "Error: stack B init error";
	error_message[10] = "Error: process status init error";
	error_message[11] = "Error: process status destroy error";
	error_message[12] = "Error: process status state error";
	error_message[13] = "Error: process status op error";
	error_message[14] = "Error: process status op list error";
	error_message[15] = "Error: malloc error";
	error_message[16] = "Error: unexpected error";
	error_message[17] = "sorted";
	ft_putendl_fd(error_message[error_code], 2);
	return (error_code);
}
*/