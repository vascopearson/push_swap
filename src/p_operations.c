/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:35:01 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:35:03 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	a->nbr_elements++;
	a->top_index++;
	a->nbrs[a->top_index] = b->nbrs[b->top_index];
	b->top_index--;
	b->nbr_elements--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	b->nbr_elements++;
	b->top_index++;
	b->nbrs[b->top_index] = a->nbrs[a->top_index];
	a->top_index--;
	a->nbr_elements--;
	write(1, "pb\n", 3);
}
