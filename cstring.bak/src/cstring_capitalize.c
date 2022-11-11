/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_capitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:32:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 13:59:53 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

void cstring_capitalize( cstring * self )
{
	char * begin = *self - 1;
	char * end = *self + cstring_length((const_cstring *)self);

	while (++begin < end)
		*begin = toupper(*begin);
}
