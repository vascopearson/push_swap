/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:37:13 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:37:15 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack *a, int write_op)
{
	int	top;
	int	i;

	top = a->nbrs[a->top_index];
	i = a->top_index;
	while (i > 0)
	{
		a->nbrs[i] = a->nbrs[i - 1];
		i--;
	}
	a->nbrs[0] = top;
	if (write_op)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int write_op)
{
	int	top;
	int	i;

	top = b->nbrs[b->top_index];
	i = b->top_index;
	while (i > 0)
	{
		b->nbrs[i] = b->nbrs[i - 1];
		i--;
	}
	b->nbrs[0] = top;
	if (write_op)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
