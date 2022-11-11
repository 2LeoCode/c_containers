/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:04:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:05:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_reverse( cstring * self )
{
	cstring_int * str = *self - offsetof(cstring_int, data);
	char * begin = *self;
	char * end = *self + str->length - 1;
	char tmp;

	while (begin < end)
	{
		tmp = *begin;
		*begin++ = *end;
		*end-- = tmp;
	}
}
