/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:35:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:08:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_assign( cstring * self, const_cstring other )
{
	cstring_assign_raw_n(self, other, string_length(other));
}

void cstring_assign_raw( cstring * self, const char * other )
{
	cstring_assign_raw_n(self, other, strlen(other));
}

void cstring_assign_raw_n( cstring * self, const char * other, size_t n )
{
	cstring_reserve(self, n);
	memcpy(*self, other, n * sizeof(char));
	(*self)[n] = '\0';
}
