/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_slice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:58:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:13:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_slice)( void * tab, ptrdiff_t pos, size_t n )
{
	let tb = (table *)((uint8_t *)tab - offsetof(table, data));

	if (pos < 0 || (size_t)pos > tb->size)
		return ;
	(table_remove)(tab, 0, pos);
	(table_remove)(tab, pos, n);
}
