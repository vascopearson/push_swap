/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:42:50 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:43:24 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_stack *a, t_stack *b)
{
	t_chunk	*chunks;

	chunks = init_chunk(a);
	mid_point_init(a, b, chunks, 0);
	while (chunks->nbr_chunks > 0)
		mid_point_b_to_a(a, b, chunks, b->top_index - \
				chunks->chunk_size[chunks->top_index] + 1);
	free(chunks);
}

void	mid_point_init(t_stack *a, t_stack *b, t_chunk *chunks, int bottom)
{
	t_array	*array;
	int		mid_index;

	if (one_or_two_elements(a, 1, b, bottom))
		return ;
	if (sorted_stack(a, 1, b, bottom))
		return ;
	array = put_stack_in_array(a, a->top_index, bottom);
	quick_sort(array, 0, array->size - 1);
	mid_index = array->size / 2;
	chunks->nbr_chunks++;
	chunks->top_index++;
	chunks->chunk_size[chunks->top_index] = pb_smaller_than_mid_init(a, b, \
			array->nbrs[mid_index], a->top_index - bottom + 1);
	free(array);
	mid_point_init(a, b, chunks, bottom);
}

void	mid_point(t_stack *a, t_stack *b, t_chunk *chunks, int bottom)
{
	t_array	*array;
	int		mid_index;

	if (one_or_two_elements(a, 1, b, bottom))
	{
		chunks->top_index_a--;
		chunks->nbr_chunks_a--;
		return ;
	}
	if (sorted_chunk(a, 1, b, chunks))
	{
		chunks->top_index_a--;
		chunks->nbr_chunks_a--;
		return ;
	}
	array = put_stack_in_array(a, a->top_index, bottom);
	quick_sort(array, 0, array->size - 1);
	mid_index = array->size / 2;
	chunks->nbr_chunks++;
	chunks->top_index++;
	chunks->chunk_size[chunks->top_index] = pb_smaller_than_mid(a, b, \
			array->nbrs[mid_index], a->top_index - bottom + 1);
	chunks->chunk_size_a[chunks->top_index] /= 2;
	free(array);
	mid_point(a, b, chunks, bottom);
}

void	quick_sort(t_array *array, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = partition(array, low, high);
		quick_sort(array, low, p - 1);
		quick_sort(array, p + 1, high);
	}
}

int	partition(t_array *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array->nbrs[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (array->nbrs[j] < pivot)
		{
			i++;
			swap(array, i, j);
		}
		j++;
	}
	swap(array, i + 1, high);
	return (i + 1);
}
