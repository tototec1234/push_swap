/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:47:51 by torinoue          #+#    #+#             */
/*   Updated: 2024/11/12 17:12:30 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_triangle(t_stack **a, t_stack **b);
static int	push_continuously(t_stack **a, t_stack **b, int trgt_indx, \
int contnue);
static int	transfer_sorted_to_bottom(t_stack **a, t_stack **b, \
int contnue, int next_trgt);

int	proc_sort_b(t_stack **a, t_stack **b, t_proc *proc_state)
{
	set_sorted_order_index_in_stack(*b);
	create_triangle(a, b);
	return (perform_post_sort_b(*a, proc_state));
}

static void	create_triangle(t_stack **a, t_stack **b)
{
	t_stack	*current_node;
	int		contnue;
	int		trgt_indx;
	int		next_trgt;

	trgt_indx = 0;
	next_trgt = 0;
	current_node = (*b)->next;
	while (*b != (*b)->next)
	{
		if (current_node->index == trgt_indx)
		{
			contnue = cnt_elems_consecutive_target(trgt_indx, *b);
			next_trgt += push_continuously(a, b, trgt_indx, contnue);
			trgt_indx += transfer_sorted_to_bottom(a, b, next_trgt, contnue);
			current_node = (*b)->next;
		}
		else
			current_node = current_node->next;
	}
}

static int	push_continuously(t_stack **a, t_stack **b, \
int trgt_indx, int contnue)
{
	int		next_trgt;

	next_trgt = 0;
	while (1)
	{
		if ((*b)->next->index == trgt_indx + contnue)
		{
			next_trgt += execute_and_write(a, b, PA);
			if (contnue == 0)
				return (next_trgt);
			contnue--;
		}
		else
		{
			if (!contnue && get_current_pos(*b, trgt_indx) > \
				ft_stacklen(*b) / 2 + 1)
				execute_and_write(a, b, RRB);
			else
				execute_and_write(a, b, RB);
		}
	}
}

static int	transfer_sorted_to_bottom(t_stack **a, t_stack **b, \
int next_trgt, int contnue)
{
	int	ret;
	int	required_rotation_count;

	ret = 0;
	while (contnue + 1 > 0)
	{
		required_rotation_count = cnt_elems_consecutive_target(next_trgt, *b);
		if ((*b)->next->index == next_trgt + required_rotation_count)
			execute_and_write(a, b, RR);
		else
			execute_and_write(a, b, RA);
		(contnue)--;
		ret++;
	}
	return (ret);
}
