/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:11:54 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 21:46:26 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void * (vec_from)( const void * other )
{
	const t_vec_int * other_int = get_const_vec_int(other);

	return (vec_from_array)(
		other_int->elem_size, (const void *)other_int->data, other_int->size,
		other_int->cpy_fun, other_int->del_fun
	);
}

void * (vec_from_array)( size_t elem_size, const void * array, size_t n,
	vec_cpy_f * cpy_fun, vec_del_f * del_fun )
{
	t_vec_int * self = malloc(sizeof(t_vec_int) + elem_size * n);

	if (!self)
		err_throw("vec_from_array: out of memory");
	self->elem_size = elem_size;
	self->cpy_fun = cpy_fun;
	self->del_fun = del_fun;
	(vec_reserve)(self, n);
	if (cpy_fun)
	{
		for (size_t i = 0; i < n; ++i)
			cpy_fun(
				(void *)((uint8_t *)self->data + i * elem_size),
				(void *)((uint8_t *)array + i * elem_size)
			);
	}
	else
		memcpy(
			(uint8_t *)self->data,
			array,
			elem_size * n
		);
	self->size = n;
	return (void *)&self->size;
}
