/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_string_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:25:33 by mathmart          #+#    #+#             */
/*   Updated: 2021/12/11 22:26:54 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	*ps_free_string_array(char ***string_array)
{
	size_t	index;

	if (*string_array != NULL)
	{
		index = 0;
		while ((*string_array)[index])
		{
			if ((*string_array)[index])
				free((*string_array)[index]);
			(*string_array)[index] = NULL;
			index++;
		}
		if ((*string_array))
			free(*string_array);
		*string_array = NULL;
	}
	return (NULL);
}
