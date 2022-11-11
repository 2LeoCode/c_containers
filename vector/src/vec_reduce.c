/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:44:33 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:13:28 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_reduce)( const void * self, void * res_ptr, int (*func)() )
{
	(vec_reduce_range)(self, res_ptr, 0, get_const_vec_int(self)->size, func);
}

void (vec_reduce_range)( const void * self, void * res_ptr, ptrdiff_t pos, size_t n,
	int (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);
	const void * data = self_int->data + pos * self_int->elem_size;

	if (n == 0)
		return;
	memcpy(res_ptr, data, self_int->elem_size);
	for (ptrdiff_t i = pos + 1; i < pos + n; ++i)
	{
		data += self_int->elem_size;
		if (func(res_ptr, data, res_ptr))
			err_throw("vec_reduce_range: function returned non-zero");
	}
}
