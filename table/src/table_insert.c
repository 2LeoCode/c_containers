/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:46:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/18 11:55:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_insert)( void * tab_addr, ptrdiff_t pos, const void * data_ptr, size_t n )
{
	let tb = (table *)(*(uint8_t **)tab_addr - offsetof(table, data));

	if (pos < 0 || (size_t)pos > tb->size)
		table_break(ERANGE);
	if (!n)
		return ;
	(table_reserve)(tab_addr, n < tb->size ? tb->size * 2 : tb->size + n);
	tb = (table *)(*(uint8_t **)tab_addr - offsetof(table, data));
	memmove(tb->data + tb->elemsize * (pos + n),
		tb->data + tb->elemsize * pos, (tb->size - pos) * tb->elemsize);
	if (tb->cpy_fun)
	{
		for (size_t i = 0; i < n; ++i)
			if (tb->cpy_fun(tb->data + tb->elemsize * (pos + i),
			data_ptr + tb->elemsize * i))
				table_break(ENOMEM);
	}
	else
		memcpy(tb->data + tb->elemsize * pos, data_ptr, n * tb->elemsize);
	tb->size += n;
}
