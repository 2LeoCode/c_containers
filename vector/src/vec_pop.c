/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:52:36 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_pop_back)( void * self, size_t n )
{
	(vec_pop)(self, get_vec_int(self)->size - n, n);
}

void (vec_pop_front)( void * self, size_t n )
{
	(vec_pop)(self, 0, n);
}

void (vec_pop)( void * self, ptrdiff_t pos, size_t n )
{
	t_vec_int * self_int = get_vec_int(self);

	if (self_int->del_fun)
	{
		for (size_t i = 0; i < n; ++i)
			self_int->del_fun(
				(void *)((uint8_t *)self_int->data + (pos + i) * self_int->elem_size)
			);
	}
	memmove(
		(uint8_t *)self_int->data + pos * self_int->elem_size,
		(uint8_t *)self_int->data + (pos + n) * self_int->elem_size,
		(self_int->size - pos - n) * self_int->elem_size
	);
	self_int->size -= n;
}
