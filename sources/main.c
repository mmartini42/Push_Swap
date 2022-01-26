/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:49:13 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/14 05:41:07 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static char	**ps_check_args(char **av, int ac)
{
	size_t	i;
	char	**nbrs;

	i = 1;
	nbrs = NULL;
	while (av[i])
	{
		if (ps_is_nbr(av[i]) == false)
			ps_error_pars(nbrs, ac);
		nbrs = ft_add_str_to_str_array(nbrs, av[i], true);
		i++;
	}
	ft_check_identical(nbrs, ac);
	return (nbrs);
}

int	main(int ac, char **av)
{
	t_box	*box;
	char	**nbrs;

	nbrs = NULL;
	if (ac <= 1)
		return (ps_error_args());
	if (ac == 2)
		nbrs = ps_parsing(av[1], ac);
	else
		nbrs = ps_check_args(av, ac);
	box = ps_box_create(nbrs);
	if (!box)
	{
		ps_final_free(ac, nbrs);
		return (ps_error_args());
	}
	list_clear(box->stack_a, free);
	free(box);
	ps_final_free(ac, nbrs);
	return (0);
}
