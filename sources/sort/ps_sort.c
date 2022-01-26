/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:05:11 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 06:27:44 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ps_mid_sort(t_box *box)
{
	while (list_size(box->stack_a) > 3)
	{
		fill_sorted_values(box, box->stack_a);
		lowest_to_top(box, &box->stack_a,
			box->sorted_values[0]);
		free(box->sorted_values);
		box->sorted_values = NULL;
		ps_push(box, &box->stack_a, &box->stack_b, true);
	}
	ps_hard_sort(box);
	ps_push(box, &box->stack_b, &box->stack_a, true);
	ps_push(box, &box->stack_b, &box->stack_a, true);
}

void	fill_sorted_values(t_box *box, t_list *stack)
{
	int	stack_size;
	int	*sorted_values;
	int	index;

	stack_size = list_size(stack);
	sorted_values = ft_calloc(stack_size, sizeof(int));
	if (sorted_values == NULL)
	{
		ps_free_box(&box);
		ft_putstr_fdnl(2, "Error");
		exit(0);
		return ;
	}
	index = -1;
	while (++index < stack_size)
		sorted_values[index] = ps_get_stack_value(stack, index);
	quick_sort(sorted_values, 0, stack_size - 1);
	box->sorted_values = sorted_values;
}

void	lowest_to_top(t_box *box, t_list **stack, int lowest)
{
	if (ps_get_value_index(*stack, lowest) > list_size(*stack) / 2)
		while (ps_get_stack_value(box->stack_a, 0) != lowest)
			ps_reverse(box, stack, true);
	else
		while (ps_get_stack_value(box->stack_a, 0) != lowest)
			ps_rotate(box, stack, true);
}

void	ps_hard_sort(t_box *box)
{
	int	first;
	int	second;
	int	third;

	first = ps_get_stack_value(box->stack_a, 0);
	second = ps_get_stack_value(box->stack_a, 1);
	third = ps_get_stack_value(box->stack_a, 2);
	if (first > second && first < third)
		ps_swap(box, box->stack_a, true);
	else if (first > second && second > third)
	{
		ps_swap(box, box->stack_a, true);
		ps_reverse(box, &box->stack_a, true);
	}
	else if (first > second && first > third && second < third)
		ps_rotate(box, &box->stack_a, true);
	else if (first < second && first < third && second > third)
	{
		ps_swap(box, box->stack_a, true);
		ps_rotate(box, &box->stack_a, true);
	}
	else if (first < second && first > third)
		ps_reverse(box, &box->stack_a, true);
}

void	ps_little_sort(t_box *box, t_list *stack)
{
	int	first;
	int	second;

	first = ps_get_stack_value(stack, 0);
	second = ps_get_stack_value(stack, 1);
	if (first > second)
		ps_swap(box, stack, true);
}
