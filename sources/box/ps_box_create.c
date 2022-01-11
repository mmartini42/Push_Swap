/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_box_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:23:27 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/12 18:45:02 by mathmart         ###   ########.fr       */
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

static t_stack_elem	*ps_create_elem(char *data)
{
	t_stack_elem	*elem;

	elem = ft_calloc(1, sizeof(t_stack_elem));
	if (!elem)
		return (NULL);
	elem->value = ps_atoi(data);
	return (elem);
}

static void	ps_fill_box(t_box *box, char **nbrs)
{
	size_t	i;

	i = 0;
	while (i < box->size)
	{
		list_add_back_new(&box->stack_a, \
			list_create_elem(ps_create_elem(nbrs[i])));
		i++;
	}
}

t_box	*ps_box_create(char **nbrs)
{
	t_box	*box;

	box = ps_box_init(nbrs);
	if (ps_check_box(box) == false)
		ps_free_box(box);
	ps_fill_box(box, nbrs);
	return (box);
}
