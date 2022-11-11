/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:35:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 13:59:13 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_assign( cstring * self, const_cstring * other )
{
	cstring_assign_raw_n(self, *other, cstring_length(other));
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
