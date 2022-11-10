/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:45:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/09 08:46:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"
#include <errno.h>

jmp_buf	CSTRING_ERRBUF = { };

$RETURNS_TWICE
int cstring_break( void )
{
	return setjmp(CSTRING_ERRBUF);
}

$NORETURN
void cstring_throw( int err )
{
	errno = err;
	longjmp(CSTRING_ERRBUF, err);
}
