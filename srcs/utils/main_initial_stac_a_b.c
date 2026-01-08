/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:49:33 by toruinoue         #+#    #+#             */
/*   Updated: 2024/11/12 20:26:11 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_sntinel(t_stack **stack);
static int	store_atoi_values_in_stack_a(t_stack **stack, int num);

int	set_sentinel_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (set_sntinel(stack_b))
		return (SET_SENTINEL_ERROR);
	if (set_sntinel(stack_a))
	{
		free_stacks_and_proc_state(NULL, *stack_b, NULL);
		stack_b = NULL;
		return (SET_SENTINEL_ERROR);
	}
	return (SUCCESS);
}

int	load_stack_a_from_arguments(t_stack **stack_a, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!is_numeric_representation(argv[i]))
			return (NUMERIC_ERROR);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (OUT_OF_RANGE);
		if (store_atoi_values_in_stack_a(stack_a, num))
			return (STACK_A_INIT_ERROR);
		i++;
	}
	return (is_unique_value(*stack_a));
}

/*
int	load_stack_a_from_arguments(t_stack **stack_a, char **argv)
{
	long	num;
	int		i;
	char	*itoa_num;

	i = 1;
	while (argv[i])
	{
		if (!is_numeric_representation(argv[i]))
			return (NUMERIC_ERROR);
		num = ft_atoi(argv[i]);
		itoa_num = ft_itoa(num);
		if (!itoa_num)
			return (ITOA_ERROR);
		if (ft_strncmp(itoa_num, &argv[i][argv[i][0] == '+'], \
		ft_strlen(&argv[i][argv[i][0] == '+'])) != 0)
			return (free(itoa_num), ARGUMENTS_INVALID);
		free(itoa_num);
		if (num > INT_MAX || num < INT_MIN)
			return (OUT_OF_RANGE);
		if (store_atoi_values_in_stack_a(stack_a, num))
			return (STACK_A_INIT_ERROR);
		i++;
	}
	return (is_unique_value(*stack_a));
}
*/

static int	set_sntinel(t_stack **stack)
{
	*stack = ft_stacknew(0);
	if (!*stack)
		return (SET_SENTINEL_ERROR);
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
	(*stack)->index = INT_MIN;
	(*stack)->is_sentinel = 1;
	return (SUCCESS);
}

static int	store_atoi_values_in_stack_a(t_stack **stack, int num)
{
	t_stack	*new_stack;

	new_stack = ft_stacknew(num);
	if (!new_stack)
		return (MALLOC_ERROR);
	if (!(*stack)->prev)
		*stack = new_stack;
	else
		return (ft_addstack_back(stack, &new_stack));
	return (SUCCESS);
}

/* NULL GURD CHECK
static int set_sntinel_a(t_stack **stack)
{
	// *stack = ft_stacknew(0);
	*stack = NULL;
	if (!*stack)
		return (SET_SENTINEL_ERROR);
	// ft_putendl_fd("a失敗したので　ここには来ないはず", 2);

	(*stack)->next = *stack;
	(*stack)->prev = *stack;
	(*stack)->index = INT_MIN;
	(*stack)->is_sentinel = 1;
	return (SUCCESS);
}
int set_sentinel_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (set_sntinel(stack_b))
		return(SET_SENTINEL_ERROR);
	ft_putendl_fd("ここでSET_SENTINEL_ERROR出すはず！", 2);

	if (set_sntinel_a(stack_a))
	{
		free_stacks_and_proc_state( NULL ,*stack_b,NULL);
		stack_b = NULL;
		return(SET_SENTINEL_ERROR);
	}
	return (SUCCESS);
}
static int set_sntinel(t_stack **stack)
{
	*stack = ft_stacknew(0);
	if (!*stack)
		return (SET_SENTINEL_ERROR);
	ft_putendl_fd(" b は成功した", 2);

	(*stack)->next = *stack;
	(*stack)->prev = *stack;
	(*stack)->index = INT_MIN;
	(*stack)->is_sentinel = 1;
	return (SUCCESS);
}
*/