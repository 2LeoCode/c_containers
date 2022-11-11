/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_unquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:10:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:14:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void string_unquote( cstring * self )
{
	cstring_int * str = *self - offsetof(cstring_int, data);
	if ((*self)[0] != (*self)[str->length - 1])
		return ;
	memmove(*self, *self + 1, str->length - 1);
	(*self)[str->length -= 2] = '\0';
}
