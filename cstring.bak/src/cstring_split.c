/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:11:56 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 12:23:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

table(cstring) cstring_split( const_cstring * self, const_cstring * delim )
{
	return cstring_split_raw_n(self, *delim, string_length(delim));
}

table(cstring) cstring_split_raw( const_cstring * self, const char * delim )
{
	return cstring_split_raw_n(self, delim, strlen(delim));
}

table(cstring) cstring_split_raw_n( const_cstring * self, const char * delim, size_t n )
{
	table(cstring) ret = table_new(cstring);
	const size_t self_len = string_length(self);
	ptrdiff_t start = 0;
	ptrdiff_t end = 0;

	end = cstring_find_raw_n(self, delim, n, start);
	while (end != CSTRING_NPOS)
	{
		table_push(&ret, cstring_substr(self, start, self_len - start));
		start = end + 1;
		end = cstring_find_raw_n(self, delim, n, start);
	}
	table_push(&ret, cstring_substr(self, start, end - start));
	return ret;
}

table(cstring) cstring_split_lines( const_cstring * self )
{
	return cstring_split_raw_n(self, "\n", 1);
}
