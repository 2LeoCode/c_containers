/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:14:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:23:43 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_trim( cstring * self, const_cstring chars )
{
	cstring_trim_raw_n(self, chars, cstring_length(chars));
}

void cstring_trim_raw( cstring * self, const char * chars )
{
	cstring_trim_raw_n(self, chars, strlen(chars));
}

void cstring_trim_raw_n( cstring * self, const char * chars, size_t n )
{
	cstring_trim_left_raw_n(self, chars, n);
	cstring_trim_right_raw_n(self, chars, n);
}

void cstring_trim_left( cstring * self, const_cstring chars )
{
	cstring_trim_left_raw_n(self, chars, cstring_length(chars));
}

void cstring_trim_left_raw( cstring * self, const char * chars )
{
	cstring_trim_left_raw_n(self, chars, strlen(chars));
}

void cstring_trim_left_raw_n( cstring * self, const char * chars, size_t n )
{
	size_t size = 0;

	while ((*self)[size] && memchr(chars, (*self)[size], n))
		++size;
	cstring_erase(self, 0, size);
}

void cstring_trim_right( cstring * self, const_cstring chars )
{
	cstring_trim_right_raw_n(self, chars, cstring_length(chars));
}

void cstring_trim_right_raw( cstring * self, const char * chars )
{
	cstring_trim_right_raw_n(self, chars, strlen(chars));
}

void cstring_trim_right_raw_n( cstring * self, const char * chars, size_t n )
{
	size_t end = cstring_length(self);

	while (end && memchr(chars, (*self)[end - 1], n))
		--end;
	cstring_erase(self, end, cstring_length(self) - end);
}
