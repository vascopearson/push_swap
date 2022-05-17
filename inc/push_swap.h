/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:39:06 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 17:09:34 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	int	nbr_elements;
	int	*nbrs;
	int	top_index;
	int	largest_val_index;
	int	smallest_val_index;
}	t_stack;

typedef struct s_array
{
	int	size;
	int	*nbrs;
}	t_array;

typedef struct s_chunk
{
	int	nbr_chunks;
	int	nbr_chunks_a;
	int	top_index;
	int	top_index_a;
	int	*chunk_size;
	int	*chunk_size_a;
}	t_chunk;

t_stack	*init_stack(int size, char **values);

t_stack	*init_second_stack(int size);

t_chunk	*init_chunk(t_stack *stack);

t_array	*init_array(int top, int low);

int		check_errors(int argc, char **argv);

int		sorted(t_stack *a);

int		ft_is_nbr(int argc, char **argv);

int		ft_duplicates(int argc, char **argv);

int		ft_nbr_in_range(int argc, char **argv);

long	ft_atoi_(const char *str);

int		ft_isdigit_(char *nbr);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a, int write_op);

void	rb(t_stack *b, int write_op);

void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a, int write_op);

void	rrb(t_stack *b, int write_op);

void	rrr(t_stack *a, t_stack *b);

void	sa(t_stack *a, int write_op);

void	sb(t_stack *b, int write_op);

void	ss(t_stack *a, t_stack *b);

void	sort(t_stack *a, t_stack *b);

void	sort_up_to_5(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);

void	sort_4_5(t_stack *a, t_stack *b);

void	sort_big(t_stack *a, t_stack *b);

void	quick_sort(t_array *array, int low, int high);

int		partition(t_array *array, int low, int high);

void	find_largest(t_stack *stack);

void	find_smallest(t_stack *stack);

void	swap(t_array *array, int i, int j);

t_array	*put_stack_in_array(t_stack *t_stack, int top, int low);

int		pb_smaller_than_mid(t_stack *a, t_stack *b, int mid, int size);

int		pb_smaller_than_mid_init(t_stack *a, t_stack *b, int mid, int size);

int		helper(t_stack *a, t_stack *b, int mid, int chunk_size);

int		pa_geq_than_mid(t_stack *a, t_stack *b, int mid, int size);

void	mid_point_init(t_stack *a, t_stack *b, t_chunk *chunks, int bottom);

void	mid_point(t_stack *a, t_stack *b, t_chunk *chunks, int bottom);

void	mid_point_b_to_a(t_stack *a, t_stack *b, t_chunk *chunks, int bottom);

int		mid_point_help(t_stack *a, t_stack *b, t_chunk *chunks, int bottom);

int		one_or_two_elements(t_stack *stack, int stck, t_stack *other, int bot);

int		sorted_chunk(t_stack *stack, int stck, t_stack *other, t_chunk *chunks);

int		sorted_stack(t_stack *stack, int stck, t_stack *other, int bottom);

void	pass_chunk(t_stack *stack, int stck, t_stack *other, t_chunk *chunks);

void	free_stacks(t_stack *a, t_stack *b);

void	free_chunks(t_chunk *chunks);

void	free_array(t_array *array);

#endif
