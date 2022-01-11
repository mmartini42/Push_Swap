/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_final_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:12:36 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/11 18:14:19 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ps_final_free(int ac, char **nbrs)
{
	if (ac == 2)
		ps_free_string_array(&nbrs);
	else
		free(nbrs);
	nbrs = NULL;
}
