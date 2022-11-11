/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:31:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 08:53:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

int cstring_print( const_cstring self )
{
	return cstring_fprint(1, self);
}

int cstring_println( const_cstring self )
{
	return cstring_fprintln(1, self);
}

int cstring_fprint( int fd, const_cstring * self )
{
	return write(fd, string_data(self), cstring_length(self));
}

int cstring_fprintln( int fd, const_cstring * self )
{
	const int ret = cstring_fprint(fd, self);
	if (ret < 0)
		return ret;
	return ret + write(fd, "\n", 1);
}
