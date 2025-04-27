/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:37 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 07:26:27 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **numbers)
{
	int	i;

	if (numbers == NULL)
		return ;
	i = 0;
	while (numbers[i] != NULL)
		free(numbers[i++]);
	free(numbers);
}

int	check_min_is_top(t_stack *stack_a)
{
	int	min;

	if (stack_a == NULL)
		return (0);
	min = stack_a->n;
	while (stack_a != NULL)
	{
		if (stack_a->n < min)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	is_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (stack_a->n > stack_a->next->n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static void	check_numbers(int argc, char **argv, int i, int j)
{
	int		k;
	char	**numbers;

	while (i < argc)
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		while (numbers[j] != NULL)
		{
			k = 0;
			if (numbers[j][k] == '-' || numbers[j][k] == '+')
				k++;
			if (!numbers[j][k])
				ft_putstr_fd("Error\n", 2, numbers, NULL);
			while (numbers[j][k])
			{
				if (!(numbers[j][k] >= '0' && numbers[j][k] <= '9'))
					ft_putstr_fd("Error\n", 2, numbers, NULL);
				k++;
			}
			j++;
		}
		free_split(numbers);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_numbers(argc, argv, 1, 0);
	full_stack_a(&stack_a, argc, argv);
	ft_index_stack(stack_a);
	if (is_sorted(stack_a) == 0)
		return (ft_lstclear(&stack_a), 0);
	size = ft_lstsize(stack_a);
	if (size == 2)
		return (sa(&stack_a), ft_lstclear(&stack_a), 0);
	if (size == 3)
		return (sort_three(&stack_a), ft_lstclear(&stack_a), 0);
	if (size == 4 || size == 5)
		return (sort_five(&stack_a, &stack_b), 0);
	sort(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
