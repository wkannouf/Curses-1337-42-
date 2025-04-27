/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:31 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 06:13:12 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	new_node = ft_lstnew((*stack_a)->n);
	if (!new_node)
		return ;
	ft_lstadd_front(stack_b, new_node);
	ft_lstdelone(stack_a);
}

void	sb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
}

void	rb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	rotate(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (c == 2)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else
	{
		rra(stack_a);
		rrb(stack_b);
	}
}
