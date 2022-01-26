/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:45:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/01/26 02:14:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_H
# define PUSH_SWAP_FUNC_H

# include "Push_swap.h"

/* Utils */
int		ps_atoi(char *str);
void	*ps_free_string_array(char ***string_array);

/* Parsing */
char	**ps_parsing(char *str, int ac);
bool	ps_is_nbr(char	*nbr);
void	ft_check_identical(char **nbrs, int ac);

/*  Memory */
void	ps_final_free(int ac, char **nbrs);

/* Errors */
int		ps_error_args(void);
void	ps_error_pars(char **nbrs, int ac);

/* Stack */
t_stack_elem	*ps_create_elem(int data);

/* Box */
t_box	*ps_box_init(char **nbrs);
t_box	*ps_box_create(char **nbrs);
void	ps_free_box(t_box *box);
int		ps_get_stack_value(t_list *stack, int index);
int		ps_get_value_index(t_list *stack, int value);

/* Actions */
void	ps_swap(t_box *box, t_list *stack, bool value);
void	ps_rotate(t_box *box, t_list **stack, bool value);
void	ps_reverse(t_box *box, t_list **stack, bool value);
void	ps_push(t_box *box, t_list **from, t_list **to, bool value);

#endif
