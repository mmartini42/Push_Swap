/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:05:20 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/11 23:24:16 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool	ps_is_nbr(char	*nbr)
{
	size_t	i;

	i = 0;
	while (nbr[i])
	{
		if (i == 0 && nbr[i] == '-')
			i++;
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (false);
		i++;
	}
	ft_atoi(nbr);
	return (true);
}

void	ps_parsing(char *str, char **nbrs)
{
	size_t	i;

	if (!str || ft_strlen(str) == 0)
		ps_error_args();
	nbrs = ft_split(str, " ");
	i = 0;
	while (nbrs[i])
	{
		if (ps_is_nbr(nbrs[i]) == false)
			ps_error_pars(nbrs);
		i++;
	}
}
