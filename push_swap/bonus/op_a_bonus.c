/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:31 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 04:09:55 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;

	if (!stack_b || !*stack_b || !stack_a)
		return ;
	new_node = ft_lstnew((*stack_b)->n);
	if (!new_node)
		return ;
	ft_lstadd_front(stack_a, new_node);
	ft_lstdelone(stack_b);
}

void	ra(t_stack **stack_a)
{
	t_stack	*new_node;

	if (!stack_a || !*stack_a)
		return ;
	new_node = ft_lstnew((*stack_a)->n);
	if (!new_node)
		return ;
	ft_lstadd_back(stack_a, new_node);
	ft_lstdelone(stack_a);
}

void	sa(t_stack **stack_a)
{
	int	temp;

	if (!stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->n;
	(*stack_a)->n = (*stack_a)->next->n;
	(*stack_a)->next->n = temp;
}

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
