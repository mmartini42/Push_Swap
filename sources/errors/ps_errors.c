/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:28:50 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/11 22:55:11 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ps_error_args(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	ps_error_pars(char **nbrs)
{
	ps_free_string_array(&nbrs);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}
