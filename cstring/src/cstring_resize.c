/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:23:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 12:11:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_resize( cstring * self, size_t n )
{
	cstring_resize_fill(self, n, '\0');
}

void cstring_resize_fill( cstring * self, size_t n, char c )
{
	cstring_int * tmp;

	if (n != cstring_length(self))
		cstring_realloc(self, n);
	tmp = *self - offsetof(cstring_int, data);
	if (n > tmp->length)
		memset(*self + tmp->length + 1, c, (n - tmp->length) * sizeof(char));
	if (n < tmp->length)
		tmp->data[n] = '\0';
	tmp->length = n;
}
