/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:36:30 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 14:37:33 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	find_largest(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = stack->top_index;
	max = stack->nbrs[i];
	index = i;
	while (i >= 0)
	{
		if (stack->nbrs[i] > max)
		{
			max = stack->nbrs[i];
			index = i;
		}
		i--;
	}
	stack->largest_val_index = index;
}

void	find_smallest(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = stack->top_index;
	min = stack->nbrs[i];
	index = i;
	while (i >= 0)
	{
		if (stack->nbrs[i] < min)
		{
			min = stack->nbrs[i];
			index = i;
		}
		i--;
	}
	stack->smallest_val_index = index;
}

void	swap(t_array *array, int i, int j)
{
	int	temp;

	temp = array->nbrs[i];
	array->nbrs[i] = array->nbrs[j];
	array->nbrs[j] = temp;
}

t_array	*put_stack_in_array(t_stack *t_stack, int top, int low)
{
	t_array	*array;
	int		i;

	array = init_array(top, low);
	array->size = top - low + 1;
	i = 0;
	while (i <= top - low)
	{
		array->nbrs[i] = t_stack->nbrs[top - i];
		i++;
	}
	return (array);
}

t_array	*init_array(int top, int low)
{
	t_array	*array;

	array = (t_array *)malloc(sizeof(t_array));
	if (!array)
		return (NULL);
	array->size = 0;
	array->nbrs = ft_calloc(sizeof(int), top - low + 1);
	return (array);
}
