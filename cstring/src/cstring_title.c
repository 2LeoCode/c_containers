/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_title.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:43:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 11:45:06 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_title( cstring * self )
{
	char * begin = *self;
	char * end = *self + cstring_length(*self);

	while (begin < end)
	{
		while (begin < end && !isalnum(*begin))
			++begin;
		*begin = toupper(*begin);
		while (isalnum(*++begin))
			*begin = tolower(*begin);
	}
}
