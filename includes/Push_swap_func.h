/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:45:01 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/11 23:29:34 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FUNC_H
# define PUSH_SWAP_FUNC_H

# include "Push_swap.h"

/* Utils */
size_t	ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);
bool	ft_contains_char(char *str, char c);
void	*ft_calloc(size_t quantity, size_t type_size);
char	*ft_strndup(const char *str, size_t n, bool free_str);
bool	is_whitespace(char c);
void	*ps_free_string_array(char ***string_array);
char	*ft_append_strs(char *s1, char *s2, bool free_s1, bool free_s2);
char	**ft_add_str_to_str_array(char **str_array, char *str, bool free_array);

/* Parsing */
void	ps_parsing(char *str, char **nbrs);
bool	ps_is_nbr(char	*nbr);

/* Errors */
int		ps_error_args(void);
void	ps_error_pars(char **nbrs);

#endif
