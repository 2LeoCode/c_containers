/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:09:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 12:10:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

size_t cstring_length( const_cstring * self )
{
	return ((cstring_int *)(*self - offsetof(cstring_int, data)))->length;
}
