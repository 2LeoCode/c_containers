/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_capitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:32:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:42:55 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_capitalize( cstring * self )
{
	char * begin = *self - 1;
	char * end = *self + cstring_length(*self);

	while (++begin < end)
		*begin = toupper(*begin);
}
