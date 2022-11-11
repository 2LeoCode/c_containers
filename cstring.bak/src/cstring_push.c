/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:59:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_push( cstring * self, char c )
{
	cstring_int * str;

	cstring_reserve(self, cstring_length(self) + 1);
	str = *self - offsetof(cstring_int, data);
	(*self)[str->length] = c;
	(*self)[str->length += 1] = '\0';
}
