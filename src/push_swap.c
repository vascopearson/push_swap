/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:35:11 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 17:06:26 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h" 

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argc, argv);
	b = init_second_stack(argc);
	if (argc < 2 || (argc == 2 && ft_is_nbr(argc, argv)))
	{
		free_stacks(a, b);
		return (0);
	}
	if (check_errors(argc, argv))
	{
		free_stacks(a, b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!sorted(a))
		sort(a, b);
	free_stacks(a, b);
	return (0);
}

t_stack	*init_stack(int size, char **values)
{
	t_stack	*stack;
	int		i;
	int		j;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->nbr_elements = size - 1;
	stack->nbrs = (int *)ft_calloc(sizeof(int), size);
	stack->top_index = -1;
	stack->largest_val_index = 0;
	stack->smallest_val_index = 0;
	i = size - 2;
	j = 1;
	while (i >= 0)
	{
		stack->nbrs[i] = ft_atoi_(values[j]);
		stack->top_index++;
		i--;
		j++;
	}
	return (stack);
}

t_stack	*init_second_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->nbr_elements = 0;
	stack->top_index = -1;
	stack->nbrs = (int *)ft_calloc(sizeof(int), size);
	stack->largest_val_index = 0;
	stack->smallest_val_index = 0;
	return (stack);
}

int	check_errors(int argc, char **argv)
{
	if (ft_is_nbr(argc, argv) && \
	ft_nbr_in_range(argc, argv) && !ft_duplicates(argc, argv))
		return (0);
	return (1);
}

int	sorted(t_stack *a)
{
	int	i;

	i = a->top_index;
	while (i > 0)
	{
		if (a->nbrs[i] > a->nbrs[i - 1])
			return (0);
		i--;
	}
	return (1);
}
