/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:26:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:32:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "table_internal.h"

size_t (table_size)( const void * tab )
{
	return ((const table *)((const uint8_t *)tab - offsetof(table, data)))
		->size;
}

size_t (table_capacity)( const void * tab )
{
	return ((const table *)((const uint8_t *)tab - offsetof(table, data)))
		->capacity;
}

cpy_f * (table_cpy_fun)( const void * tab )
{
	return ((const table *)((const uint8_t *)tab - offsetof(table, data)))
		->cpy_fun;
} 

clr_f * (table_clr_fun)( const void * tab )
{
	return ((const table *)((const uint8_t *)tab - offsetof(table, data)))
		->clr_fun;
}
