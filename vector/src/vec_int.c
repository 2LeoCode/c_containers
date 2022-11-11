/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:44:09 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 21:44:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

t_vec_int * get_vec_int( void * vec )
{
	return (t_vec_int *)((uint8_t *)vec - offsetof(t_vec_int, size));
}

const t_vec_int * get_const_vec_int( const void * vec )
{
	return (const t_vec_int *)((const uint8_t *)vec - offsetof(t_vec_int, size));
}
