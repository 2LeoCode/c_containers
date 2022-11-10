/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_contains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:23:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/09 09:29:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

bool cstring_contains( const_cstring * self, const_cstring * other )
{
	return cstring_contains_raw_n(self, *other, string_length(other));
}

bool cstring_contains_raw( const_cstring * self, const char * other )
{
	return cstring_contains_raw_n(self, other, strlen(other));
}

bool cstring_contains_raw_n( const_cstring * self, const char * other, size_t n )
{
	return cstring_find_raw_n(self, other, n, 0) != CSTRING_NPOS;
}
