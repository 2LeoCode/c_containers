/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:23:23 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 12:33:58 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

cstring cstring_substr( const_cstring * self, ptrdiff_t pos, size_t n )
{
	const size_t self_len = string_length(self);
	cstring ret;

	if (pos > self_len)
		return cstring_new();
	if (n > self_len - pos)
		n = self_len - pos;
	ret = cstring_new_with_capacity(n);
	cstring_append_raw_n(ret, *self + pos, n);
	return ret;
}

cstring cstring_substr_to( const_cstring * self, ptrdiff_t pos )
{
	return cstring_substr(self, 0, pos);
}

cstring cstring_substr_from( const_cstring * self, ptrdiff_t pos )
{
	return cstring_substr(self, pos, string_length(self) - pos);
}
