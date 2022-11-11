/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:10:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_quote( cstring * self, char c )
{
	cstring_int * str;

	cstring_reserve(self, cstring_length(self) + 2);
	str = *self - offsetof(cstring_int, data);
	memmove(*self + 1, *self, str->length + 1);
	**self = c;
	cstring_push(self, c);
}
