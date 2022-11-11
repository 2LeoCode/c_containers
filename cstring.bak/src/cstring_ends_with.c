/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_ends_with.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:05:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/09 09:06:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

bool cstring_ends_with( const_cstring * self, const_cstring * other )
{
	return cstring_ends_with_raw_n(self, *other, string_length(other));
}

bool cstring_ends_with_raw( const_cstring * self, const char * other )
{
	return cstring_ends_with_raw_n(self, other, strlen(other));
}

bool cstring_ends_with_raw_n( const_cstring * self, const char * other, size_t n )
{
	const size_t self_len = string_length(self);
	return self_len < n ? false : !memcmp(*self + self_len - n, other, n);
}
