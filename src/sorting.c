/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:40:27 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 12:41:06 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (a->nbr_elements < 6)
		sort_up_to_5(a, b);
	else
		sort_big(a, b);
}

void	sort_up_to_5(t_stack *a, t_stack *b)
{
	if (a->nbr_elements == 2)
		sa(a, 1);
	else if (a->nbr_elements == 3)
		sort_3(a);
	else
		sort_4_5(a, b);
}

void	sort_3(t_stack *a)
{
	find_largest(a);
	find_smallest(a);
	if (a->largest_val_index == 1 && a->smallest_val_index == 2)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->largest_val_index == 0 && a->smallest_val_index == 1)
		sa(a, 1);
	else if (a->largest_val_index == 1 && a->smallest_val_index == 0)
		rra(a, 1);
	else if (a->largest_val_index == 2 && a->smallest_val_index == 1)
		ra(a, 1);
	else if (a->largest_val_index == 2 && a->smallest_val_index == 0)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

void	sort_4_5(t_stack *a, t_stack *b)
{
	int	pa_times;

	pa_times = a->nbr_elements - 3;
	find_smallest(a);
	while (a->top_index > 2)
	{
		while (a->smallest_val_index != a->top_index)
		{
			if (a->smallest_val_index < 2)
				rra(a, 1);
			if (a->smallest_val_index >= 2)
				ra(a, 1);
			find_smallest(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (pa_times > 0)
	{
		pa(a, b);
		pa_times--;
	}
}
