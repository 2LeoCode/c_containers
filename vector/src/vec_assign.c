/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:43:27 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 17:31:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_assign)( void * self_ptr, const void * other )
{
	(vec_assign_array)(
		self_ptr, get_const_vec_int(other)->data,
		get_const_vec_int(other)->size
	);
}

void (vec_assign_array)( void * self_ptr, const void * array, size_t n )
{
	t_vec_int * self_int;

	(vec_clear)(*(void **)self_ptr);
	(vec_reserve)(self_ptr, n);
	self_int = get_vec_int(*(void **)self_ptr);
	if (self_int->cpy_fun)
	{
		for (size_t i = 0; i < n; ++i)
			self_int->cpy_fun(
				(void *)((uint8_t *)self_int->data + i * self_int->elem_size),
				(const void *)((const uint8_t *)array + i * self_int->elem_size)
			);
	}
	else
		memcpy(
			(uint8_t *)self_int->data,
			array,
			self_int->elem_size * n
		);
	self_int->size = n;
}
