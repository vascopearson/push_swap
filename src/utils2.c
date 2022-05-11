/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:38:14 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 14:38:44 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_chunk	*init_chunk(t_stack *stack)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	chunk->chunk_size = ft_calloc(sizeof(int), stack->nbr_elements);
	chunk->chunk_size_a = ft_calloc(sizeof(int), stack->nbr_elements);
	chunk->nbr_chunks = 0;
	chunk->nbr_chunks_a = 0;
	chunk->top_index = -1;
	chunk->top_index_a = -1;
	return (chunk);
}

int	pb_smaller_than_mid(t_stack *a, t_stack *b, int mid, int size)
{
	int	chunk_size;
	int	counter;

	counter = 0;
	chunk_size = 0;
	while (size > 0)
	{
		if (a->nbrs[a->top_index] < mid)
		{
			pb(a, b);
			chunk_size++;
		}
		else
		{
			ra(a, 1);
			counter++;
		}
		size--;
	}
	while (counter--)
		rra(a, 1);
	return (chunk_size);
}

int	pb_smaller_than_mid_init(t_stack *a, t_stack *b, int mid, int size)
{
	int	chunk_size;

	chunk_size = 0;
	chunk_size = helper(a, b, mid, chunk_size);
	size -= chunk_size;
	while (size > 0)
	{
		if (a->nbrs[a->top_index] < mid)
		{
			pb(a, b);
			chunk_size++;
		}
		else
			ra(a, 1);
		size--;
	}
	return (chunk_size);
}

int	helper(t_stack *a, t_stack *b, int mid, int chunk_size)
{
	while (a->nbrs[a->top_index] < mid)
	{
		pb(a, b);
		chunk_size++;
	}
	while (a->nbrs[0] < mid)
	{
		rra(a, 1);
		pb(a, b);
		chunk_size++;
	}
	return (chunk_size);
}

int	pa_geq_than_mid(t_stack *a, t_stack *b, int mid, int size)
{
	int	chunk_size;
	int	counter;

	chunk_size = 0;
	counter = 0;
	while (size)
	{
		if (b->nbrs[b->top_index] >= mid)
		{
			pa(a, b);
			chunk_size++;
		}
		else
		{
			rb(b, 1);
			counter++;
		}
		size--;
	}
	while (counter--)
		rrb(b, 1);
	return (chunk_size);
}
