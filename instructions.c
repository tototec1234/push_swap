#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*prev;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

