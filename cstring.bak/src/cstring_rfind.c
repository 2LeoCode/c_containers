/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_rfind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:21:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 11:05:41 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

ptrdiff_t cstring_rfind( const_cstring * self, const_cstring * other, ptrdiff_t pos )
{
	return cstring_rfind_raw_n(self, *other, string_length(other), pos);
}

ptrdiff_t cstring_rfind_raw( const_cstring * self, const char * other, ptrdiff_t pos )
{
	return cstring_rfind_raw_n(self, other, strlen(other), pos);
}

ptrdiff_t cstring_rfind_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos )
{
	const size_t self_len = string_length(self);

	if (pos < n)
		return CSTRING_NPOS;
	for (const char * it = *self + pos - n; it >= *self; --it)
		if (!memcmp(it, other, n))
			return it - *self;
	return CSTRING_NPOS;
}
