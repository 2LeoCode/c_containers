/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_shrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:23:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/18 11:30:42 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_shrink)( void * tab_addr )
{
	let tb = (table *)(*(uint8_t **)tab_addr - offsetof(table, data));

	table * tmp = realloc(tb, sizeof(table) + tb->size * tb->elemsize);
	if (!tmp)
		table_break(ENOMEM);
	tmp->capacity = tmp->size;
	*(void **)tab_addr = tmp->data;
}
