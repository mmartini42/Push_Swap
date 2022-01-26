/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:49:13 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 06:31:21 by mathmart         ###   ########.fr       */
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

bool	check(t_box *box)
{
	int	index;
	int	current;
	int	next;

	if (list_size(box->stack_b) > 0)
		return (false);
	index = -1;
	while (++index < list_size(box->stack_a) - 1)
	{
		current = ps_get_stack_value(box->stack_a, index);
		next = ps_get_stack_value(box->stack_a, index + 1);
		if (current >= next)
			return (false);
	}
	return (true);
}

static void	sort(t_box *box)
{
	if (check(box))
		return ;
	if (box->size >= 500)
		ps_sort_big(box, 10);
	else if (box->size >= 100)
		ps_sort_big(box, 5);
	else if (box->size >= 50)
		ps_sort_big(box, 4);
	else if (box->size >= 6)
		ps_sort_big(box, 2);
	else if (box->size >= 4)
		ps_mid_sort(box);
	else if (box->size == 3)
		ps_hard_sort(box);
	else if (box->size == 2)
		ps_little_sort(box, box->stack_a);
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
	sort(box);
	list_clear(box->stack_a, free);
	free(box);
	ps_final_free(ac, nbrs);
	return (0);
}
