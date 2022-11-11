/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:39:13 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 12:48:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

cstring cstring_format( const char * fmt, ... )
{
	va_list args;
	cstring ret;

	va_start(args, fmt);
	ret = cstring_format_v(fmt, args);
	va_end(args);
	return ret;
}

cstring cstring_format_v( const char * fmt, va_list args )
{
	cstring ret = cstring_new_with_capacity(vsnprintf(NULL, 0, fmt, args));

	vsprintf(*ret, fmt, args);
	return ret;
}
