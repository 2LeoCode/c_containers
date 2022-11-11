/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:27:01 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_push_back)( void * self_ptr, const void * values, size_t n )
{
	(vec_push)(
		self_ptr, get_vec_int(*(void **)self_ptr)->size, values, n
	);
}

void (vec_push_front)( void * self_ptr, const void * values, size_t n )
{
	(vec_push)(self_ptr, 0, values, n);
}

void (vec_push)( void * self_ptr, ptrdiff_t pos, const void * values, size_t n )
{
	const size_t old_size = get_vec_int(*(void **)self_ptr)->size;
	t_vec_int * self_int;

	(vec_reserve)(self_ptr, n > old_size * 2 ? n :old_size * 2);
	self_int = get_vec_int(*(void **)self_ptr);
	memmove(
		(uint8_t *)self_int->data + (pos + n) * self_int->elem_size,
		(uint8_t *)self_int->data + pos * self_int->elem_size,
		(self_int->size - pos) * self_int->elem_size
	);
	if (self_int->cpy_fun)
	{
		for (size_t i = 0; i < n; ++i)
			self_int->cpy_fun(
				(void *)((uint8_t *)self_int->data + (pos + i) * self_int->elem_size),
				(const void *)((const uint8_t *)values + i * self_int->elem_size)
			);
	}
	else
		memcpy(
			(uint8_t *)self_int->data + pos * self_int->elem_size,
			values,
			self_int->elem_size * n
		);
	self_int->size += n;
}
