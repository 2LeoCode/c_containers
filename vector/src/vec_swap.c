/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:22:44 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_swap)( void * self_ptr, void * other_ptr )
{
	if (self_ptr == other_ptr)
		return ;
	*(uintptr_t *)self_ptr ^= *(uintptr_t *)other_ptr;
	*(uintptr_t *)other_ptr ^= *(uintptr_t *)self_ptr;
	*(uintptr_t *)self_ptr ^= *(uintptr_t *)other_ptr;
}

void (vec_swap_elements)( void * self, ptrdiff_t pos1, void * other, ptrdiff_t pos2 )
{
	return (vec_swap_ranges)(self, pos1, 1, other, pos2, 1);
}

void (vec_swap_ranges)( void * self, ptrdiff_t pos1, size_t n1, void * other, ptrdiff_t pos2, size_t n2 )
{
	t_vec_int * self_int = get_vec_int(self);
	t_vec_int * other_int = get_vec_int(other);

	if (pos1 > self_int->size || pos2 > other_int->size)
		err_throw("vec_swap_ranges: out of range");
	if (pos1 + n1 > self_int->size)
		n1 = self_int->size - pos1;
	if (pos2 + n2 > other_int->size)
		n2 = other_int->size - pos2;
	uint8_t tmp[n1 * self_int->elem_size];

	memcpy(tmp, self + pos1 * self_int->elem_size, n1 * self_int->elem_size);
	memcpy(self + pos1 * self_int->elem_size, other + pos2 * other_int->elem_size, n2 * self_int->elem_size);
	memcpy(other + pos2 * other_int->elem_size, tmp, n1 * self_int->elem_size);
}
