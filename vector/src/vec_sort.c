/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:33:34 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 17:47:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

static void merge( size_t elem_size, void * left, size_t left_size,
	void * right, size_t right_size, int (*cmp)() )
{
	size_t left_index = 0;
	size_t right_index = 0;
	int cmp_ret;
	void * tmp = malloc(elem_size * (left_size + right_size));

	if (!tmp)
		err_throw("vec_sort: out of memory");
	while (left_index != left_size && right_index != right_size)
	{
		cmp_ret = cmp(
			left + left_index * elem_size, right + right_index * elem_size
		);
		if (cmp_ret <= 0)
			memcpy(
				tmp + (left_index + right_index) * elem_size,
				left + left_index++ * elem_size, elem_size
			);
		else
			memcpy(
				tmp + (left_index + right_index) * elem_size,
				right + right_index++ * elem_size, elem_size
			);
	}
	memcpy(
		tmp + (left_index + right_index) * elem_size,
		left + left_index * elem_size, elem_size * (left_size - left_index)
	);
	memcpy(
		tmp + (left_index + right_index) * elem_size,
		right + right_index * elem_size, elem_size * (right_size - right_index)
	);
	memcpy(left, tmp, elem_size * (left_size + right_size));
	free(tmp);
}

static void merge_sort( size_t elem_size, void * start, size_t size,
	int (*cmp)() )
{
	const size_t left_size = size / 2;
	const size_t right_size = size - size / 2;

	if (size < 2)
		return ;
	merge_sort(elem_size, start, left_size, cmp);
	merge_sort(elem_size, start + elem_size * left_size, right_size, cmp);
	merge(
		elem_size, start, left_size, start + elem_size * left_size,
		right_size, cmp
	);
}

void (vec_sort)( void * self, int (*func)() )
{
	merge_sort(
		get_vec_int(self)->data,
		get_vec_int(self)->size,
		get_vec_int(self)->elem_size,
		func
	);
}
