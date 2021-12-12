/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_box_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:15 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/12 16:16:43 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static int	ps_size_nbrs(char **nbrs)
{
	size_t	i;

	if (!nbrs)
		return (0);
	i = 0;
	while (nbrs[i])
		i++;
	return (i);
}

t_box	*px_box_init(char **nbrs)
{
	t_box	*box;

	box = ft_calloc(1, sizeof(t_box));
	if (!box)
		return (NULL);
	box->size = ps_size_nbrs(nbrs);
	box->stack_a = NULL;
	box->stack_b = NULL;
}
