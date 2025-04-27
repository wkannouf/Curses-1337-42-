/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:49 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/14 23:33:39 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_duplicate(ssize_t num, t_stack *stack_a)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	while (stack_a != NULL)
	{
		if (stack_a->n == num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	full_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;
	t_stack	*temp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			if (is_duplicate(ft_atoi(numbers[j]), *stack_a) == 0)
				ft_putstr_fd("Error\n", 2, numbers, stack_a);
			temp = ft_lstnew(ft_atoi(numbers[j]));
			if (!temp)
				ft_putstr_fd("Error\n", 2, numbers, stack_a);
			ft_lstadd_back(stack_a, temp);
			j++;
		}
		free_split(numbers);
		i++;
	}
}
