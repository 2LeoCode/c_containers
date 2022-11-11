/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:53:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:13:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cstring_internal.h"

static int cstring_printf(FILE * stream, const struct printf_info * info, const void * const * args)
{
	const_cstring * const self = args[0];

	(void)info;
	return fwrite(cstring_data(self), sizeof(char), cstring_length(self), stream);
}

static int cstring_arginfo(const struct printf_info * info,
	size_t n,
	int * argtypes,
	int * sizes)
{
	if (n > 0)
		argtypes[0] = PA_POINTER;
	return 1;
}

$CONSTRUCTOR
static void cstring_printf_init(void)
{
	if (register_printf_specifier('S', cstring_printf, cstring_arginfo))
	{
		fprintf(stderr, "cstring: Failed to register printf specifier 'S'.\n");
		exit(EXIT_FAILURE);
	}
}
