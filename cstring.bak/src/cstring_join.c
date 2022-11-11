/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:30:10 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 12:38:21 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

cstring cstring_join( const_cstring * strings, size_t n, const_cstring * delim )
{
	return cstring_join_raw_n(strings, n, *delim, string_length(delim));
}

cstring cstring_join_raw( const_cstring * strings, size_t n, const char * delim )
{
	return cstring_join_raw_n(strings, n, delim, strlen(delim));
}

cstring cstring_join_raw_n( const_cstring * strings, size_t n, const char * delim, size_t delim_len )
{
	size_t total_len = 0;
	size_t i;
	cstring ret;

	for (i = 0; i < n; ++i)
		total_len += string_length(strings + i);
	total_len += delim_len * (n - 1);
	ret = cstring_new_with_capacity(total_len);
	for (i = 0; i < n; ++i)
	{
		if (i)
			string_append_raw_n(ret, delim, delim_len);
		string_append(ret, strings + i);
	}
	return ret;
}

cstring cstring_join_lines( const_cstring * strings, size_t n )
{
	return cstring_join_raw_n(strings, n, "\n", 1);
}
