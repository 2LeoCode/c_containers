/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:47:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 14:00:09 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

int cstring_compare( const_cstring * self, const_cstring * other )
{
	return cstring_compare_raw_n(self, *other, cstring_length(other));
}

int cstring_compare_raw( const_cstring * self, const char * other )
{
	return cstring_compare_raw_n(self, other, strlen(other));
}

int cstring_compare_raw_n( const_cstring * self, const char * other, size_t n )
{
	const size_t self_len = cstring_length(self);
	const int ret = memcmp(
		*self, other,
		(self_len < n ? self_len : n) * sizeof(char)
	);
	return ret < 0 ? -1 : ret ? 1 : n == self_len ? 0 : n < self_len ? 1 : -1;
}
