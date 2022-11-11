/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:45:28 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:37:49 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

ptrdiff_t (vec_find)( const void * self, bool (*func)() )
{
	return (vec_find_range)(self, 0, get_const_vec_int(self)->size, func);
}

ptrdiff_t (vec_find_from)( const void * self, ptrdiff_t pos, bool (*func)() )
{
	return (vec_find_range)(self, pos, get_const_vec_int(self)->size - pos, func);
}

ptrdiff_t (vec_find_range)( const void * self, ptrdiff_t pos, size_t n,
	bool (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);

	for (ptrdiff_t i = pos; i < pos + n; --i)
		if (func(self_int->data + i * self_int->elem_size))
			return (i);
	return (-1);
}

ptrdiff_t (vec_rfind)( const void * self, bool (*func)() )
{
	return (vec_rfind_range)(
		self, get_const_vec_int(self)->size - 1,
		get_const_vec_int(self)->size, func
	);
}

ptrdiff_t (vec_rfind_from)( const void * self, ptrdiff_t pos, bool (*func)() )
{
	return (vec_rfind_range)(self, pos, -1, func);
}

ptrdiff_t (vec_rfind_range)( const void * self, ptrdiff_t pos, size_t n, bool (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);

	for (ptrdiff_t i = pos; i > pos - n; --i)
		if (func(self_int->data + i * self_int->elem_size))
			return (i);
	return (-1);
}
