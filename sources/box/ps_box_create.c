/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_box_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:23:27 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 06:25:40 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static bool	ps_check_box(t_box *box)
{
	if (box->size == 0)
		return (false);
	if (box->stack_a != NULL)
		return (false);
	if (box->stack_b != NULL)
		return (false);
	return (true);
}

t_stack_elem	*ps_create_elem(int data)
{
	t_stack_elem	*elem;

	elem = ft_calloc(1, sizeof(t_stack_elem));
	if (elem != NULL)
		elem->value = data;
	return (elem);
}

static bool	ps_fill_box(t_box *box, char **nbrs)
{
	size_t	i;
	int		value;

	i = 0;
	while (i < box->size)
	{
		value = ps_atoi(nbrs[i]);
		if (ps_get_value_index(box->stack_a, value) != -1)
			return (false);
		list_add_back_new(&box->stack_a, ps_create_elem((int)value));
		i++;
	}
	return (true);
}

t_box	*ps_box_create(char **nbrs)
{
	t_box	*box;

	box = ps_box_init(nbrs);
	if (ps_check_box(box) == false)
		ps_free_box(&box);
	if (!ps_fill_box(box, nbrs))
	{
		ps_free_box(&box);
		return (NULL);
	}
	return (box);
}
