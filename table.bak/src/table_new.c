/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:55:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 21:24:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void * (table_new)( size_t elemsize, void * cpy_fun, void * clr_fun )
{
	table * tb = malloc(sizeof(table));

	if (!tb)
		table_break(ENOMEM);
	tb->elemsize = elemsize;
	tb->size = tb->capacity = 0;
	tb->cpy_fun = cpy_fun;
	tb->clr_fun = clr_fun;
	return tb->data;
}

void * (table_from)( const void * other )
{
	let src = (const table *)((uint8_t *)other - offsetof(table, data));
	let dstdata = (table_new)(src->elemsize, src->cpy_fun, src->clr_fun);

	(table_insert)(&dstdata, 0, src->data, src->size);
	return dstdata;
}
