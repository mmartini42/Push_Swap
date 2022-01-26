/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:45:43 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 06:10:05 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

# include "Push_swap.h"

typedef struct s_box
{
	size_t	size;
	t_list	*stack_a;
	t_list	*stack_b;
	int		*max;
	int		*sorted_values;
}			t_box;

typedef struct s_stack_elem
{
	int	value;
}				t_stack_elem;

/* Stack */
t_stack_elem	*ps_create_elem(int data);

#endif
