/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 07:01:04 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 07:01:27 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_ok(t_stack **stack_a, char *ops)
{
	if (!ops && is_sorted(*stack_a) == 0)
	{
		ft_putstr_fd("OK\n", 1, NULL, NULL);
		return (0);
	}
	else if (!ops && is_sorted(*stack_a) != 0)
	{
		ft_putstr_fd("KO\n", 1, NULL, NULL);
		return (0);
	}
	return (1);
}

char	**take_ops(char *op, char *ops, t_stack **stack_a)
{
	char	**split_ops;

	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break ;
		if (ft_strncmp(op, "sa\n", 3) && ft_strncmp(op, "sb\n", 3) && \
			ft_strncmp(op, "ss\n", 3) && ft_strncmp(op, "pa\n", 3) && \
			ft_strncmp(op, "pb\n", 3) && ft_strncmp(op, "ra\n", 3) && \
			ft_strncmp(op, "rb\n", 3) && ft_strncmp(op, "rr\n", 3) && \
			ft_strncmp(op, "rra\n", 4) && ft_strncmp(op, "rrb\n", 4) && \
			ft_strncmp(op, "rrr\n", 4))
		{
			free(op);
			free(ops);
			ft_putstr_fd("Error\n", 2, NULL, NULL);
		}
		ops = ft_strjoin(ops, op);
		free(op);
	}
	if (is_ok(stack_a, ops) == 0)
		return (free(ops), NULL);
	split_ops = ft_split(ops, '\n');
	return (free(ops), split_ops);
}
