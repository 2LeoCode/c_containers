/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:36 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:14:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void * (vec_front)( void * self )
{
	return get_vec_int(self)->data;
}

void * (vec_cfront)( const void * self )
{
	return get_const_vec_int(self)->data;
}

