/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_capacity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 12:11:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

size_t cstring_capacity( const_cstring * self )
{
	return ((cstring_int *)(*self - offsetof(cstring_int, data)))->capacity;
}
