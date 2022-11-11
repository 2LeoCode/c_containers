/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:25:55 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_reverse)( void * self )
{
	(vec_reverse_range)(self, 0, get_vec_int(self)->size);
}

void (vec_reverse_range)( void * self, ptrdiff_t pos, size_t n )
{
	t_vec_int * self_int = get_vec_int(self);
	size_t i = pos;
	size_t j = pos + n - 1;

	while (i < j)
	{
		(vec_swap_elements)(self, i, self, j);
		++i;
		--j;
	}
}
