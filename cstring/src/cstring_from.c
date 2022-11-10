/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:29:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:11:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"
#include <errno.h>

cstring cstring_from( const_cstring * other )
{
	return (cstring_from_raw_n(*other, cstring_length(other)));
}

cstring cstring_from_raw( const char * other )
{
	return (cstring_from_raw_n(other, strlen(other)));
}

cstring cstring_from_raw_n( const char * other, size_t n )
{
	cstring_int * str = cstring_new_with_capacity(n);
	str->length = n;
	str->capacity = n;
	memcpy(str->data, other, n * sizeof(char));
	str->data[n] = '\0';
	return (str->data);
}
