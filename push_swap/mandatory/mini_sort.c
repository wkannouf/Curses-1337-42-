/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:00:47 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 03:10:04 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->n;
	mid = (*stack_a)->next->n;
	bottom = (*stack_a)->next->next->n;
	if (top > mid && mid < bottom && bottom > top)
		sa(stack_a);
	else if (top > mid && mid > bottom)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && mid < bottom && bottom < top)
		ra(stack_a);
	else if (top < mid && mid > bottom && bottom > top)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bottom && bottom < top)
		rra(stack_a);
}

static int	find_min(t_stack *stack)
{
	int	min;

	min = stack->n;
	while (stack)
	{
		if (stack->n < min)
			min = stack->n;
		stack = stack->next;
	}
	return (min);
}

static int	find_next_min(t_stack *stack, int min)
{
	int	next_min;
	int	found;

	found = 0;
	next_min = 0;
	while (stack)
	{
		if (stack->n > min && (found == 0 || stack->n < next_min))
		{
			next_min = stack->n;
			found = 1;
		}
		stack = stack->next;
	}
	return (next_min);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	next_min;
	int	size;

	size = ft_lstsize(*stack_a);
	min = find_min(*stack_a);
	next_min = find_next_min(*stack_a, min);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->n == min || (*stack_a)->n == next_min)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->n > (*stack_a)->next->n)
			sa(stack_a);
	}
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
