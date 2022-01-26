/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:36:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 06:24:03 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	*ps_free_box(t_box **box)
{
	list_clear((*box)->stack_a, free);
	(*box)->stack_a = NULL;
	list_clear((*box)->stack_b, free);
	(*box)->stack_b = NULL;
	free((*box)->sorted_values);
	(*box)->sorted_values = NULL;
	free((*box)->max);
	(*box)->max = NULL;
	free(*box);
	box = NULL;
	return (NULL);
}
