/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:23:41 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:37:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_iter)( const void * self, void (*func)() )
{
	(vec_iter_range)(self, 0, get_const_vec_int(self)->size, func);
}

void (vec_iter_range)( const void * self, ptrdiff_t pos, size_t n, void (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);

	for (ptrdiff_t i = pos; i < pos + n; ++i)
		func((const void *)(self_int->data + i * self_int->elem_size));
}

void (vec_riter)( const void * self, void (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);
	(vec_riter_range)(self, self_int->size - 1, self_int->size, func);
}

void (vec_riter_range)( const void * self, ptrdiff_t pos, size_t n, void (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);

	for (ptrdiff_t i = pos; i > pos - n; --i)
		func((const void *)(self_int->data + i * self_int->elem_size));
}
