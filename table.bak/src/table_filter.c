/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:02:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 08:29:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "table_internal.h"

void (table_filter)( void * tab, bool (*cnd_fun)() )
{
	let tb = (table *)((uint8_t *)tab - offsetof(table, data));
	size_t n;
	size_t i = 0;

	while (i < tb->size)
	{
		n = 0;
		while (!cnd_fun(tb->data + (i + n) * tb->elemsize))
			++n;
		if (n)
			(table_remove)(tab, i, n);
		else
			++i;
	}
}
