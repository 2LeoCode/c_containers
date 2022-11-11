/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:00:54 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:10:54 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_resize)( void * self_ptr, size_t n, const void * value )
{
	t_vec_int * self_int;

	(vec_reserve)(self_ptr, n);
	self_int = get_vec_int(*(void**)self_ptr);
	if (self_int->del_fun)
	{
		for (size_t i = n; i < self_int->size; ++i)
			self_int->del_fun(
				(void *)((uint8_t *)self_int->data + i * self_int->elem_size)
			);
	}
	if (self_int->cpy_fun)
	{
		for (size_t i = self_int->size; i < n; ++i)
			self_int->cpy_fun(
				(void *)((uint8_t *)self_int->data + i * self_int->elem_size),
				value
			);
	}
	else for (size_t i = self_int->size; i < n; ++i)
		memcpy(
			(void *)((uint8_t *)self_int->data + i * self_int->elem_size),
			value,
			self_int->elem_size
		);
	self_int->size = n;
}
