/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_slice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:19:03 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vec_int.h"

void * (vec_slice)( void * self, ptrdiff_t pos, size_t n )
{
	t_vec_int * self_int = get_vec_int(self);
	t_vec_int * new_int = malloc(sizeof(*new_int) + self_int->elem_size * n);

	if (!new_int)
		err_throw("vec_slice: out of memory");
	new_int->elem_size = self_int->elem_size;
	new_int->cpy_fun = self_int->cpy_fun;
	new_int->del_fun = self_int->del_fun;
	new_int->size = n;
	new_int->capacity = n;
	memcpy(
		new_int->data, (void *)(self_int->data + pos * self_int->elem_size),
		n * self_int->elem_size
	);
	(vec_pop)(self, pos, n);
	return (void *)&new_int->size;
}
