/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:31:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:43:16 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void * (table_assign)( void * tab_addr, const void * other )
{
	let src = (const table *)((uint8_t *)other - offsetof(table, data));
	let tb = (table *)(*(uint8_t **)tab_addr - offsetof(table, data));

	(table_clear)(tb->data);
	tb->elemsize = src->elemsize;
	tb->cpy_fun = src->cpy_fun;
	(table_insert)(tab_addr, 0, src->data, src->size);
	(table_shrink)(tab_addr);
	return *(void **)tab_addr;
}
