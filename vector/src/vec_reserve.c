/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:09:20 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:13:22 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_reserve)( void * self_ptr, size_t n )
{
	t_vec_int * self_int = get_vec_int(*(void**)self_ptr);

	if (n < self_int->capacity)
		return ;
	self_int->capacity = n;
	self_int = realloc(self_int, sizeof(*self_int) + n * self_int->elem_size);
	if (!self_int)
		err_throw("vec_reserve: out of memory");
	*(void**)self_ptr = self_int->data;
}
