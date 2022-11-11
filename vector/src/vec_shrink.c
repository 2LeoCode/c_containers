/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_shrink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:20:07 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:21:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_shrink)( void * self_ptr )
{
	t_vec_int * self_int = get_vec_int(*(void**)self_ptr);

	if (self_int->size == self_int->capacity)
		return ;
	self_int->capacity = self_int->size;
	self_int = realloc(
		self_int, sizeof(*self_int) + self_int->size * self_int->elem_size
	);
	if (!self_int)
		err_throw("vec_shrink: out of memory");
	*(void**)self_ptr = self_int->data;
}
