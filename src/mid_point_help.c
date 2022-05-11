/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:34:11 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 14:44:21 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	one_or_two_elements(t_stack *stack, int stck, t_stack *other, int bot)
{
	if (stack->top_index - bot > 1)
		return (0);
	if (stack->top_index - bot == 1)
	{
		if (stck == 1 && stack->nbrs[stack->top_index] > \
		stack->nbrs[stack->top_index - 1])
			sa(stack, 1);
		if (stck == 2 && stack->nbrs[stack->top_index] < \
		stack->nbrs[stack->top_index - 1])
		{
			sb(stack, 1);
			pa(other, stack);
			pa(other, stack);
		}
		else if (stck == 2 && stack->nbrs[stack->top_index] > \
		stack->nbrs[stack->top_index - 1])
		{
			pa(other, stack);
			pa(other, stack);
		}
	}
	if (stack->top_index - bot == 0 && stck == 2)
		pa(other, stack);
	return (1);
}

int	sorted_stack(t_stack *stack, int stck, t_stack *other, int bottom)
{
	int	sorted;
	int	top;

	top = stack->top_index;
	sorted = 1;
	while (top > bottom)
	{
		if (stck == 1 && stack->nbrs[top] > stack->nbrs[top - 1])
			sorted = 0;
		if (stck == 2 && stack->nbrs[top] < stack->nbrs[top - 1])
			sorted = 0;
	top--;
	}
	if (sorted && stck == 2)
	{
		while (stack->nbr_elements > 0)
			pa(other, stack);
	}
	return (sorted);
}

int	sorted_chunk(t_stack *stack, int stck, t_stack *other, t_chunk *chunks)
{
	int	sorted;
	int	top;
	int	bottom;

	top = stack->top_index;
	if (stck == 1)
		bottom = top - chunks->chunk_size_a[chunks->top_index_a];
	else
		bottom = top - chunks->chunk_size[chunks->top_index];
	sorted = 1;
	while (top > bottom)
	{
		if (stck == 1 && stack->nbrs[top] > stack->nbrs[top - 1])
			sorted = 0;
		if (stck == 2 && stack->nbrs[top] < stack->nbrs[top - 1])
			sorted = 0;
	top--;
	}
	if (sorted && stck == 2)
		pass_chunk(stack, stck, other, chunks);
	return (sorted);
}

void	pass_chunk(t_stack *stack, int stck, t_stack *other, t_chunk *chunks)
{
	int	top;
	int	bottom;

	top = stack->top_index;
	if (stck == 1)
	{
		bottom = top - chunks->chunk_size_a[chunks->top_index_a];
		while (top > bottom)
		{
			pb(stack, other);
			top--;
		}
	}
	else
	{
		bottom = top - chunks->chunk_size[chunks->top_index];
		while (top > bottom)
		{
			pa(other, stack);
			top--;
		}
	}
}
