/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:00:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:42:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "table_internal.h"

void (table_resize)( void * tab_addr, size_t n )
{
	table * tb;

	(table_reserve)(tab_addr, n);
	tb = (table *)(*(uint8_t **)tab_addr - offsetof(table, data));
	if (n > tb->size)
	{
		if (tb->cpy_fun)
		{
			for (size_t i = tb->size; i < n; ++i)
				if (tb->cpy_fun(tb->data + tb->size, NULL))
					table_break(ENOMEM);
		}
		else
			memset(tb->data + tb->size * tb->elemsize, 0, n * tb->elemsize);
	}
	if (n < tb->size && tb->clr_fun)
		for (size_t i = n; i < tb->size; ++i)
			tb->clr_fun(tb->data + tb->elemsize * (n + i));
	tb->size = n;
}
