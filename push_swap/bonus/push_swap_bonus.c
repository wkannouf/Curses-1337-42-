/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:37 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 07:03:57 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	is_sorted(t_stack *stack_a)
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

static void	sort(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(op, "rrb", 3) == 0)
		rrb(stack_b);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		rotate(stack_a, stack_b, 3);
	else if (ft_strncmp(op, "sa", 2) == 0)
		sa(stack_a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(stack_b);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra(stack_a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb(stack_b);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rotate(stack_a, stack_b, 2);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split_ops;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	check_numbers(argc, argv, 1, 0);
	full_stack_a(&stack_a, argc, argv);
	split_ops = take_ops(NULL, NULL, &stack_a);
	if (split_ops == NULL)
		return (ft_lstclear(&stack_a), 0);
	while (split_ops[i])
		sort(split_ops[i++], &stack_a, &stack_b);
	free_split(split_ops);
	if (is_sorted(stack_a) == 0 && stack_b == NULL)
		ft_putstr_fd("OK\n", 1, NULL, NULL);
	else
		ft_putstr_fd("KO\n", 1, NULL, NULL);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
