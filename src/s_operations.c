/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:37:35 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:40:17 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack *a, int write_op)
{
	int	temp;

	temp = a->nbrs[a->top_index];
	a->nbrs[a->top_index] = a->nbrs[a->top_index - 1];
	a->nbrs[a->top_index - 1] = temp;
	if (write_op)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int write_op)
{
	int	temp;

	temp = b->nbrs[b->top_index];
	b->nbrs[b->top_index] = b->nbrs[b->top_index - 1];
	b->nbrs[b->top_index - 1] = temp;
	if (write_op)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
