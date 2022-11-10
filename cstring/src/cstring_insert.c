/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:13:20 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:47:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cstring_internal.h"

void cstring_insert( cstring * self, const_cstring other, ptrdiff_t pos )
{
	cstring_insert_raw_n(self, pos, other, cstring_length(other));
}

void cstring_insert_raw( cstring * self, const char * other, ptrdiff_t pos )
{
	cstring_insert_raw_n(self, pos, other, strlen(other));
}

void cstring_insert_raw_n( cstring * self, const char * other, size_t n, ptrdiff_t pos )
{
	cstring_int * str = *self - offsetof(cstring_int, data);
	const size_t new_len = str->length + n;

	if (n == 0)
		return ;
	cstring_reserve(self, new_len > str->length * 2 ? new_len : str->length * 2);
	memmove(*self + (pos + n) * sizeof(char), self + pos * sizeof(char), (str->length - pos) * sizeof(char));
	memcpy(*self + pos, other, n * sizeof(char));
	str->length -= n;
}

void cstring_append( cstring * self, const_cstring other )
{
	cstring_append_raw_n(self, other, string_length(other));
}

void cstring_append_raw( cstring * self, const char * other )
{
	cstring_append_raw_n(self, other, strlen(other));
}

void cstring_append_raw_n( cstring * self, const char * other, size_t n )
{
	cstring_insert_raw_n(self, cstring_length(self), other, n);
}
