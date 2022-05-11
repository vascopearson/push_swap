/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:39:20 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 14:36:15 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	mid_point_b_to_a(t_stack *a, t_stack *b, t_chunk *chunks, int bottom)
{
	t_array	*array;
	int		mid_index;

	if (mid_point_help(a, b, chunks, bottom))
		return ;
	array = put_stack_in_array(b, b->top_index, bottom);
	quick_sort(array, 0, array->size - 1);
	mid_index = array->size / 2;
	chunks->nbr_chunks_a++;
	chunks->top_index_a++;
	chunks->chunk_size_a[chunks->top_index_a] = pa_geq_than_mid(a, b, \
			array->nbrs[mid_index], b->top_index - bottom + 1);
	chunks->chunk_size[chunks->top_index] /= 2;
	free(array);
	mid_point(a, b, chunks, a->top_index - \
			chunks->chunk_size_a[chunks->top_index_a] + 1);
}

int	mid_point_help(t_stack *a, t_stack *b, t_chunk *chunks, int bottom)
{
	if (one_or_two_elements(b, 2, a, bottom))
	{
		chunks->top_index--;
		chunks->nbr_chunks--;
		return (1);
	}
	if (sorted_chunk(b, 2, a, chunks))
	{
		chunks->top_index--;
		chunks->nbr_chunks--;
		return (1);
	}
	return (0);
}
