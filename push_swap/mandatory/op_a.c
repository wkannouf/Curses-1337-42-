/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:31 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 02:55:42 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("pa\n", 1, NULL, NULL);
}

void	ra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1, NULL, NULL);
}

void	sa(t_stack **stack_a)
{
	int	temp;

	if (!stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->n;
	(*stack_a)->n = (*stack_a)->next->n;
	(*stack_a)->next->n = temp;
	ft_putstr_fd("sa\n", 1, NULL, NULL);
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
	ft_putstr_fd("rra\n", 1, NULL, NULL);
}
