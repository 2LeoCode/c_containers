/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:40:41 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:36:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_apply)( void * self, void (*func)() )
{
	(vec_apply_range)(self, 0, get_vec_int(self)->size, func);
}

void (vec_apply_range)( void * self, ptrdiff_t pos, size_t n, void (*func)() )
{
	t_vec_int * self_int = get_vec_int(self);

	for (ptrdiff_t i = pos; i < pos + n; ++i)
		func((void *)(self_int->data + i * self_int->elem_size));
}

void (vec_rapply)( void * self, void (*func)() )
{
	t_vec_int * self_int = get_vec_int(self);

	(vec_rapply_range)(self, self_int->size - 1, self_int->size, func);
}

void (vec_rapply_range)( void * self, ptrdiff_t pos, size_t n, void (*func)() )
{
	t_vec_int * self_int = get_vec_int(self);

	for (ptrdiff_t i = pos; i > pos - n; --i)
		func((void *)(self_int->data + i * self_int->elem_size));
}
