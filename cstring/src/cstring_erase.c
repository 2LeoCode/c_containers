/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_erase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:25:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:10:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"
#include <errno.h>

void cstring_erase( cstring * self, ptrdiff_t pos, size_t n )
{
	cstring_int * str = *self - offsetof(cstring_int, data);

	if (pos > str->length)
		cstring_throw(EINVAL);
	if (pos + n > str->length)
		n = str->length - pos;
	memmove(self + pos * sizeof(char), self + (pos + n) * sizeof(char), (str->length - pos - n + 1) * sizeof(char));
	str->length -= n;
}
