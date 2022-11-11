/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:42:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:44:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void table_clear( void * tab )
{
	let tb = (table *)((uint8_t *)tab - offsetof(table, data));
	if (tb->clr_fun)
		for (size_t i = 0; i < tb->size; ++i)
			tb->clr_fun(tb->data + i * tb->elemsize);
	tb->size = 0;
}
