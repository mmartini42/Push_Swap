/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:45:01 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/12 17:28:44 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_H
# define PUSH_SWAP_FUNC_H

# include "Push_swap.h"

/* Utils */
int		ps_atoi(char *str);
void	*ps_free_string_array(char ***string_array);

/* Parsing */
char	**ps_parsing(char *str, char **nbrs);
bool	ps_is_nbr(char	*nbr);

/* Errors */
int		ps_error_args(void);
void	ps_error_pars(char **nbrs);

/* Box */
t_box	*px_box_init(char **nbrs);
t_box	*ps_box_create(char **nbrs);

#endif
