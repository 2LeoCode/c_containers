/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:15 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:37:49 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void * (vec_back)( void * self )
{
	t_vec_int * self_int = get_vec_int(self);
	return self_int->data + (self_int->size - 1) * self_int->elem_size;
}

void * (vec_cback)( const void * self )
{
	const t_vec_int * self_int = get_const_vec_int(self);
	return self_int->data + (self_int->size - 1) * self_int->elem_size;
}
