/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:05:20 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/12 15:25:58 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_check_identical(char **nbrs, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (ft_strcmp(nbrs[i], nbrs[j]) == 0 && i != j)
				ps_error_pars(nbrs, ac);
			j++;
		}
		i++;
	}
}

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
	ps_atoi(nbr);
	return (true);
}

char	**ps_parsing(char *str, int ac)
{
	size_t	i;
	char	**nbrs;

	if (!str || ft_strlen(str) == 0)
		ps_error_args();
	nbrs = ft_split(str, " ");
	i = 0;
	while (nbrs[i])
	{
		if (ps_is_nbr(nbrs[i]) == false)
			ps_error_pars(nbrs, ac);
		i++;
	}
	ft_check_identical(nbrs, ac);
	return (nbrs);
}
