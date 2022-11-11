/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_reserve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:40:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 11:24:59 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_realloc( cstring * self, size_t n )
{
	cstring_int * tmp = *self - offsetof(cstring_int, data);

	tmp = realloc(tmp, sizeof(cstring_int) + (n + 1) * sizeof(char));
	if (!tmp)
		cstring_throw(errno);
	tmp->data[n] = '\0';
	tmp->capacity = n;
	*self = tmp->data;
}

void cstring_reserve( cstring * self, size_t n )
{
	if (n <= cstring_capacity(self))
		return ;
	cstring_realloc(self, n);
}
