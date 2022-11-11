/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:42:18 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:45:07 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

size_t (vec_count)( const void * self, bool (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);
	size_t cnt = 0;
	for (size_t i = 0; i < self_int->size; ++i)
		if (func(self_int->data + i * self_int->elem_size))
			++cnt;
	return cnt;
}

size_t (vec_count_range)( const void * self, ptrdiff_t pos, size_t n, bool (*func)() )
{
	const t_vec_int * self_int = get_const_vec_int(self);
	size_t cnt = 0;
	for (ptrdiff_t i = pos; i < pos + n; ++i)
		if (func(self_int->data + i * self_int->elem_size))
			++cnt;
	return cnt;
}
