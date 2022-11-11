/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:13:43 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/21 15:51:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

void (table_destroy)( void * tab )
{
	uint8_t ** addr = tab;

	if (*addr == NULL)
		return ;
	(table_clear)(*addr);
	free(*addr - offsetof(table, data));
	*addr = NULL;
}
