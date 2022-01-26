/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 02:15:46 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 02:40:17 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static void	ps_display(t_box *box, t_list *stack,
	char *action, bool value)
{
	if (!value)
		return ;
	ft_putstr(action);
	if (box->stack_a == stack)
		ft_putchar_nl('a');
	else if (box->stack_b == stack)
		ft_putchar_nl('b');
}

void	ps_push(t_box *box, t_list **from, t_list **to, bool value)
{
	if (list_size(*from) <= 0)
		return ;
	list_add_front_new(
		to,
		ps_create_elem(((t_stack_elem *)list_get(*from, 0)->data)->value));
	list_remove(from, free, 0);
	ps_display(box, *to, "p", value);
}

void	ps_reverse(t_box *box, t_list **stack, bool value)
{
	if (list_size(*stack) <= 0)
		return ;
	list_add_front_new(
		stack,
		ps_create_elem(((t_stack_elem *)list_get(*stack,
					list_size(*stack) - 1)->data)->value));
	list_remove(stack, free, list_size(*stack) - 1);
	ps_display(box, *stack, "rr", value);
}

void	ps_rotate(t_box *box, t_list **stack, bool value)
{
	if (list_size(*stack) <= 0)
		return ;
	list_add_back_new(
		stack,
		ps_create_elem(((t_stack_elem *)list_get(*stack, 0)->data)->value));
	list_remove(stack, free, 0);
	ps_display(box, *stack, "r", value);
}

void	ps_swap(t_box *box, t_list *stack, bool value)
{
	t_stack_elem	*elem;

	if (list_size(stack) < 2)
		return ;
	elem = list_get(stack, 1)->data;
	list_get(stack, 1)->data = list_get(stack, 0)->data;
	list_get(stack, 0)->data = elem;
	ps_display(box, stack, "s", value);
}
