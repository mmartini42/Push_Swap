/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_box_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 01:16:37 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/17 01:17:13 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ps_get_stack_value(t_list *stack, int index)
{
	return (((t_stack_elem *) list_get(stack, index)->data)->value);
}

int	ps_get_value_index(t_list *stack, int value)
{
	int	index;

	index = -1;
	while (++index < list_size(stack))
		if (ps_get_stack_value(stack, index) == value)
			return (index);
	return (-1);
}
