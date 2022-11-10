/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 15:30:55 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_internal.h"

static void merge( size_t elemsize, void * left, size_t left_size,
	void * right, size_t right_size, int (* cmp_fun)() )
{
	size_t left_index = 0;
	size_t right_index = 0;
	int cmp_ret;
	void * tmp = malloc(elemsize * (left_size + right_size));

	if (!tmp)
		table_break(ENOMEM);
	while (left_index != left_size && right_index != right_size)
	{
		cmp_ret = cmp_fun(left + elemsize * left_index,
			right + elemsize * right_index);
		if (cmp_ret < 0)
		{
			memcpy(tmp + elemsize * (left_index + right_index),
				left + elemsize * left_index, elemsize);
			++left_index;
		}
		else
		{
			memcpy(tmp + elemsize * (left_index + right_index),
				right + elemsize * right_index, elemsize);
			++right_index;
		}
	}
	memcpy(tmp + elemsize * (left_index + right_index),
		left + elemsize * left_index,
		elemsize * (left_size - left_index));
	memcpy(tmp + elemsize * (left_index + right_index),
		right + elemsize * right_index,
		elemsize * (right_size - right_index));
	memcpy(left, tmp, elemsize * (left_size + right_size));
	free(tmp);
}


static void merge_sort( size_t elemsize, void * start, size_t size, int (* cmp_fun)())
{
	const let left_size = size / 2;
	const let right_size = size - size / 2;

	if (size < 2)
		return ;
	merge_sort(elemsize, start, left_size, cmp_fun);
	merge_sort(elemsize, start + elemsize * left_size, right_size, cmp_fun);
	merge(elemsize, start, left_size,
		start + elemsize * left_size, right_size, cmp_fun);
}

void (table_sort)( void * tab, int (* cmp_fun)() )
{
	let tb = (table *)((uint8_t *)tab - offsetof(table, data));

	merge_sort(tb->elemsize, tb->data, tb->size, cmp_fun);
}
