/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bzaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:07:00 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 05:39:43 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stack *stack_a)
{
	t_stack	*ptr;
	t_stack	*min;
	int		index;
	int		size;

	index = 0;
	size = ft_lstsize(stack_a);
	while (index < size)
	{
		ptr = stack_a;
		min = NULL;
		while (ptr)
		{
			if (ptr->i == -1 && (min == NULL || ptr->n < min->n))
				min = ptr;
			ptr = ptr->next;
		}
		if (min)
			min->i = index;
		index++;
	}
}

static int	find_max_index(t_stack *stack_b)
{
	int		max_index;
	t_stack	*tmp;

	if (!stack_b)
		return (-1);
	max_index = stack_b->i;
	tmp = stack_b->next;
	while (tmp)
	{
		if (tmp->i > max_index)
			max_index = tmp->i;
		tmp = tmp->next;
	}
	return (max_index);
}

static int	find_position(t_stack *stack_b, int max_index)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack_b;
	while (tmp && tmp->i != max_index)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

static void	push_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->i <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->i <= i + chunk_size)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1)
				rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;
	int	pos;
	int	half;

	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
	push_b(stack_a, stack_b, chunk_size);
	while (*stack_b)
	{
		pos = find_position(*stack_b, find_max_index(*stack_b));
		half = ft_lstsize(*stack_b) / 2;
		if (pos <= half)
			while ((*stack_b)->i != find_max_index(*stack_b))
				rb(stack_b);
		else
			while ((*stack_b)->i != find_max_index(*stack_b))
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
