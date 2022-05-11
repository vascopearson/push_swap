/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:37:22 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:37:24 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack *a, int write_op)
{
	int	bottom;
	int	i;

	bottom = a->nbrs[0];
	i = 0;
	while (i < a->top_index)
	{
		a->nbrs[i] = a->nbrs[i + 1];
		i++;
	}
	a->nbrs[a->top_index] = bottom;
	if (write_op)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int write_op)
{
	int	bottom;
	int	i;

	bottom = b->nbrs[0];
	i = 0;
	while (i < b->top_index)
	{
		b->nbrs[i] = b->nbrs[i + 1];
		i++;
	}
	b->nbrs[b->top_index] = bottom;
	if (write_op)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
