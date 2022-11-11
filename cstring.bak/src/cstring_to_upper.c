/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_to_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:29:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:32:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_to_upper( cstring * self )
{
	cstring_int * str = *self - offsetof(cstring_int, data);
	char * begin = *self;
	char * end = *self + str->length;

	while (begin < end)
		*begin++ = toupper(*begin);
}
