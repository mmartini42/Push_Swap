/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:45:43 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/12 17:44:23 by mathmart         ###   ########.fr       */
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
}			t_box;

typedef struct s_stack_elem
{
	int	value;
}				t_stack_elem;

#endif
