/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:56:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:06:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_remove)( void * tab, ptrdiff_t pos, size_t n )
{
	let tb = (table *)((uint8_t *)tab - offsetof(table, data));

	if (pos < 0 || (size_t)pos >= tb->size)
		table_break(ERANGE);
	if (!n)
		return ;
	if (n > tb->size - pos)
		n = tb->size - pos;
	if (tb->clr_fun)
		for (size_t i = 0; i < n; ++i)
			tb->clr_fun(tb->data + tb->elemsize * (pos + i));
	memcpy(tb->data + tb->elemsize * pos,
		tb->data + tb->elemsize * (pos + n),
		tb->elemsize * (tb->size - pos - n));
	tb->size -= n;
}
