/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:28:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 08:19:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_replace( cstring * self, const_cstring old, const_cstring new )
{
	string_replace_raw_n(self, old, string_length(old), new, string_length(new));
}

void cstring_replace_raw( cstring * self, const char * old, const char * new )
{
	string_replace_raw_n(self, old, strlen(old), new, strlen(new));
}

void cstring_replace_raw_n( cstring * self, const char * old, size_t old_len, const char * new, size_t new_len )
{
	size_t pos = 0;

	while ((pos = cstring_find_raw_n(self, old, old_len, pos)) != CSTRING_NPOS)
	{
		cstring_reserve(self, cstring_length(*self) + new_len - old_len);
		memcpy(*self + pos + new_len, *self + pos, string_length(*self) - pos);
		memcpy(*self + pos, new, new_len);
		pos += new_len;
	}
}

void cstring_replace_first( cstring * self, const_cstring old, const_cstring new )
{
	cstring_replace_first_raw_n(self, old, cstring_length(old), new, string_length(new));
}

void cstring_replace_first_raw( cstring * self, const char * old, const char * new )
{
	cstring_replace_first_raw_n(self, old, strlen(old), new, strlen(new));
}

void cstring_replace_first_raw_n( cstring * self, const char * old, size_t old_len, const char * new, size_t new_len )
{
	size_t pos = cstring_find_raw_n(self, old, old_len, 0);

	if (pos != CSTRING_NPOS)
	{
		cstring_reserve(self, cstring_length(*self) + new_len - old_len);
		memcpy(*self + pos + new_len, *self + pos, cstring_length(*self) - pos);
		memcpy(*self + pos, new, new_len);
	}
}

void cstring_replace_last( cstring * self, const_cstring old, const_cstring new )
{
	cstring_replace_last_raw_n(self, old, cstring_length(old), new, cstring_length(new));
}

void cstring_replace_last_raw( cstring * self, const char * old, const char * new )
{
	cstring_replace_last_raw_n(self, old, strlen(old), new, strlen(new));
}

void cstring_replace_last_raw_n( cstring * self, const char * old, size_t old_len, const char * new, size_t new_len )
{
	size_t pos = cstring_rfind_raw_n(self, old, old_len, cstring_length(*self));

	if (pos != CSTRING_NPOS)
	{
		cstring_reserve(self, cstring_length(*self) + new_len - old_len);
		memcpy(*self + pos + new_len, *self + pos, cstring_length(*self) - pos);
		memcpy(*self + pos, new, new_len);
	}
}
