/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:52:54 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_filter)( void * self, bool (*func)() )
{
	(vec_filter_range)(self, 0, get_vec_int(self)->size, func);
}

void (vec_filter_range)( void * self, bool (*func)(), ptrdiff_t pos, size_t n )
{
	t_vec_int * self_int = get_vec_int(self);
	size_t i = pos;

	while (i < pos + n)
	{
		size_t cnt = 0;
		while (!func((void *)((uint8_t *)self_int->data + (i + cnt) * self_int->elem_size)))
			++cnt;
		(vec_pop)(self, i, cnt);
	}
}
