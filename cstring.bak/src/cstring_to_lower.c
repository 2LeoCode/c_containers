/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_to_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:32:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:32:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_to_lower( cstring * self )
{
	cstring_int * str = *self - offsetof(cstring_int, data);
	char * begin = *self;
	char * end = *self + str->length;

	while (begin < end)
		*begin++ = tolower(*begin);
}
