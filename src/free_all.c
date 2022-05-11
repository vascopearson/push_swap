/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:34:22 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:34:33 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->nbrs);
	a->nbrs = NULL;
	free(a);
	free(b->nbrs);
	b->nbrs = NULL;
	free(b);
}

void	free_chunks(t_chunk *chunks)
{
	free(chunks->chunk_size);
	chunks->chunk_size = NULL;
	free(chunks->chunk_size_a);
	chunks->chunk_size_a = NULL;
	free(chunks);
}

void	free_array(t_array *array)
{
	free(array->nbrs);
	array->nbrs = NULL;
	free(array);
}
