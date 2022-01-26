/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 04:04:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 06:29:35 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	ps_fill_chunk_limits(t_box *box, int chunks)
{
	int	*sorted_values;
	int	*chunk_limits;
	int	values_per_chunk;
	int	index;

	sorted_values = box->sorted_values;
	chunk_limits = ft_calloc(chunks, sizeof(int));
	if (chunk_limits == NULL)
	{
		ps_free_box(&box);
		ft_putstr_fdnl(2, "Error");
		exit(0);
		return ;
	}
	values_per_chunk = box->size / chunks;
	index = -1;
	while (++index < chunks - 1)
		chunk_limits[index] = sorted_values[values_per_chunk * (index + 1)];
	chunk_limits[index] = sorted_values[box->size - 1];
	box->max = chunk_limits;
}

static void	ps_push_chunks(t_box *box, int chunks)
{
	int	chunk_limits_index;
	int	stack_size;
	int	index;
	int	first_a;

	chunk_limits_index = -1;
	while (++chunk_limits_index < chunks)
	{
		if (list_size(box->stack_a) <= 3)
			break ;
		stack_size = list_size(box->stack_a);
		index = -1;
		while (++index < stack_size)
		{
			if (list_size(box->stack_a) <= 3)
				break ;
			first_a = ps_get_stack_value(box->stack_a, 0);
			if (first_a < box->max[chunk_limits_index])
				ps_push(box, &box->stack_a, &box->stack_b, true);
			else
				ps_rotate(box, &box->stack_a, true);
		}
	}
}

static int	ps_sort_behavior(t_box *box)
{
	int	lowest;

	lowest = ps_get_stack_value(box->stack_a, 0);
	while (list_size(box->stack_b) > 0)
	{
		if (ps_get_stack_value(box->stack_b, 0) > ps_get_stack_value(box->stack_a, 0))
			while (ps_get_stack_value(box->stack_b, 0) > \
				ps_get_stack_value(box->stack_a, 0))
				ps_rotate(box, &box->stack_a, true);
		else if (ps_get_stack_value(box->stack_b, 0) < lowest)
		{
			lowest_to_top(box, &box->stack_a, lowest);
			lowest = ps_get_stack_value(box->stack_b, 0);
		}
		else if (ps_get_stack_value(box->stack_b, 0) < \
			ps_get_stack_value(box->stack_a, 0))
			while (ps_get_stack_value(box->stack_a, \
				list_size(box->stack_a) - 1) > ps_get_stack_value(box->stack_b, 0))
				ps_reverse(box, &box->stack_a, true);
		ps_push(box, &box->stack_b, &box->stack_a, true);
	}
	return (lowest);
}

void	ps_sort_big(t_box *box, int chunks)
{
	fill_sorted_values(box, box->stack_a);
	ps_fill_chunk_limits(box, chunks);
	ps_push_chunks(box, chunks);
	ps_hard_sort(box);
	lowest_to_top(box, &box->stack_a, ps_sort_behavior(box));
}
