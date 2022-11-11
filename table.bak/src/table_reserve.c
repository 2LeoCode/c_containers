/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_reserve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:39:54 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:08:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_reserve)( void * tab_addr, size_t n )
{
	uint8_t ** addr = tab_addr;
	let tb = (table *)(*addr - offsetof(table, data));
	table * tmp;

	if (tb->capacity >= n)
		return ;
	tmp = realloc(tb, sizeof(table) + n * tb->elemsize);
	if (!tmp)
		table_break(ENOMEM);
	tmp->capacity = n;
	*addr = tmp->data;
}
