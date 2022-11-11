/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_sentence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:45:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 11:23:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_sentence( cstring * self )
{
	char * begin = *self;
	char * end = *self + cstring_length(*self);

	while (begin < end)
	{
		while (begin < end && !isalnum(*begin))
			++begin;
		*begin = toupper(*begin);
		while (begin < end && *begin != '.' && *begin != '!' && *begin != '?'
		&& !(*begin == 'i' && isspace(begin[1]) && (begin == *self || isspace(begin[-1]))))
			*begin = tolower(*begin);
	}
}
