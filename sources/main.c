/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:49:13 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/11 23:47:59 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	ps_check_args(char **nbrs, char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (ps_is_nbr(av[i]) == false)
			ps_error_pars(nbrs);
		nbrs = ft_add_str_to_str_array(nbrs, av[i], true);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**nbrs;

	nbrs = NULL;
	if (ac <= 1)
		return (ps_error_args());
	if (ac == 2)
		ps_parsing(av[1], nbrs);
	else
		ps_check_args(nbrs, av);
}
