/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:37:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 07:26:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_apply)( void * tab, void (*app_fun)() )
{
	let tb = (table *)((uint8_t *)tab - offsetof(table, data));

	for (size_t i = 0; i < tb->size; ++i)
		app_fun(tb->data + i * tb->elemsize);
}
