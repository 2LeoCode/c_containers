/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_find_first_of.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:20:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 11:02:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

ptrdiff_t cstring_find_first_of( const_cstring * self, const_cstring * other, ptrdiff_t pos )
{
	return cstring_find_first_of_raw_n(self, *other, string_length(other), pos);
}

ptrdiff_t cstring_find_first_of_raw( const_cstring * self, const char * other, ptrdiff_t pos )
{
	return cstring_find_first_of_raw_n(self, other, strlen(other), pos);
}

ptrdiff_t cstring_find_first_of_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos )
{
	const size_t self_len = string_length(self);

	if (pos > self_len)
		return CSTRING_NPOS;
	for (const char * it = *self + pos; it < *self + self_len; ++it)
		if (memchr(other, *it, n))
			return it - *self;
	return CSTRING_NPOS;
}
