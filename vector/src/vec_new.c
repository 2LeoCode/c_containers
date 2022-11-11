/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:46:34 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:12:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void * (vec_new)( size_t elem_size, vec_cpy_f * cpy, vec_del_f * del )
{
	return (vec_new_with_capacity)(elem_size, 0, cpy, del);
}

void * (vec_new_with_capacity)( size_t elem_size, size_t capacity, vec_cpy_f * cpy, vec_del_f * del )
{
	t_vec_int * self_int = malloc(sizeof(*self_int) + elem_size * capacity);

	if (!self_int)
		err_throw("vec_new_with_capacity: out of memory");
	self_int->elem_size = elem_size;
	self_int->cpy_fun = cpy;
	self_int->del_fun = del;
	self_int->size = 0;
	self_int->capacity = capacity;
	return (void *)&self_int->size;
}
