/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_starts_with.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:59:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/09 09:05:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

bool cstring_starts_with( const_cstring * self, const_cstring * other )
{
	return cstring_starts_with_raw_n(self, *other, string_length(other));
}

bool cstring_starts_with_raw( const_cstring * self, const char * other )
{
	return cstring_starts_with_raw_n(self, other, strlen(other));
}

bool cstring_starts_with_raw_n( const_cstring * self, const char * other, size_t n )
{
	return string_length(self) < n ? false : !memcmp(*self, other, n);
}
