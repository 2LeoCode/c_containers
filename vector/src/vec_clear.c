/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:55:44 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:15:20 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_clear)( void * self )
{
	t_vec_int * self_int = get_vec_int(self);

	if (self_int->del_fun)
	{
		for (size_t i = 0; i < self_int->size; ++i)
			self_int->del_fun(
				(void *)((uint8_t *)self_int->data + i * self_int->elem_size)
			);
	}
	self_int->size = 0;
}
