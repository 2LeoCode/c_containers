/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_uncapitalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:42:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:51:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_uncapitalize( cstring * self )
{
	char * begin = *self - 1;
	char * end = *self + cstring_length(*self);

	while (++begin < end)
		*begin = tolower(*begin);
}
