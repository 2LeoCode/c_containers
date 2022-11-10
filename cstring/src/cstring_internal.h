/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:58:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/09 09:16:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTRING_INTERNAL_H
# define CSTRING_INTERNAL_H

# include "../cstring.h"
# include "common/attribute_decorators.h"

# include <printf.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdbool.h>

typedef struct s_cstring_int
{
	size_t	length;
	size_t	capacity;
	char	data[];
}	cstring_int;

void cstring_realloc( cstring * self, size_t n );

#endif
