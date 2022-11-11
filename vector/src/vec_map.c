/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:22:36 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 22:39:09 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void * (vec_map)( const void * self, size_t new_elem_size, int (*func)(),
	vec_cpy_f * cpy_fun, vec_del_f * del_fun )
{
	return (vec_map_range)(
		self, new_elem_size, 0, get_const_vec_int(self)->size,
		func, cpy_fun, del_fun
	);
}

void * (vec_map_range)( const void * self, size_t new_elem_size, ptrdiff_t pos,
	size_t n, int (*func)(), vec_cpy_f * cpy_fun, vec_del_f * del_fun )
{
	const t_vec_int * self_int = get_const_vec_int(self);
	t_vec_int * new_vec = malloc(sizeof(*new_vec) + new_elem_size * n);

	for (size_t i = 0; i < n; ++i)
	{
		if (func(
			self_int->data + (pos + i) * self_int->elem_size,
			new_vec->data + i * new_elem_size
		))
			err_throw("vec_map_range: function returned non-zero");
	}
	new_vec->size = n;
	return new_vec->data;
}
