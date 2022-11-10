/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:58:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 08:16:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"
#include <errno.h>

cstring cstring_new( void )
{
	return (cstring_new_with_capacity(0));
}

cstring string_new_with_capacity( size_t cap )
{
	cstring_int * str = malloc(sizeof(cstring_int) + (cap + 1) * sizeof(char));
	if (!str)
		cstring_throw(errno);
	str->length = 0;
	str->capacity = cap;
	*str->data = '\0';
	return (str->data);
}
