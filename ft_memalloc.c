/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:53:36 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/16 11:45:53 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *memory;

	memory = NULL;
	if (size)
	{
		memory = (void*)malloc(size);
		if (!memory)
			return (NULL);
		ft_memset(memory, 0, size);
	}
	return (memory);
}
