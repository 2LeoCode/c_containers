/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_find_last_not_of.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:11:06 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 12:11:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

ptrdiff_t cstring_find_last_not_of( const_cstring * self, const_cstring * other, ptrdiff_t pos )
{
	return cstring_find_last_not_of_raw_n(self, *other, string_length(other), pos);
}

ptrdiff_t cstring_find_last_not_of_raw( const_cstring * self, const char * other, ptrdiff_t pos )
{
	return cstring_find_last_not_of_raw_n(self, other, strlen(other), pos);
}

ptrdiff_t cstring_find_last_not_of_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos )
{
	const size_t self_len = string_length(self);

	if (!pos)
		return CSTRING_NPOS;
	for (const char * it = *self + pos; it >= *self; --it)
		if (!memchr(other, *it, n))
			return it - *self;
	return CSTRING_NPOS;
}
