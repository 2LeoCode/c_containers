/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:07:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/09 09:30:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "cstring_internal.h"

ptrdiff_t cstring_find( const_cstring * self, const_cstring * other, ptrdiff_t pos )
{
	return cstring_find_raw_n(self, *other, string_length(other), pos);
}

ptrdiff_t cstring_find_raw( const_cstring * self, const char * other, ptrdiff_t pos )
{
	return cstring_find_raw_n(self, other, strlen(other), pos);
}

ptrdiff_t cstring_find_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos )
{
	const size_t self_len = string_length(self);

	return pos > self_len ? CSTRING_NPOS : self_len - pos < n ? CSTRING_NPOS : (char *)memmem(*self + pos, self_len - pos, other, n) - *self;
}
