/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:03:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:03:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_pop( cstring * self )
{
	cstring_int * str = *self - offsetof(cstring_int, data);
	(*self)[str->length -= 1] = '\0';
}
