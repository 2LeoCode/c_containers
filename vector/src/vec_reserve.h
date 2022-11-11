/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reserve.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:07:57 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:10:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_RESERVE_H
# define VEC_RESERVE_H

# define vec_reserve_( self, n ) \
	vec_reserve(&(self), n)

void vec_reserve( void * self_ptr, size_t n );

#endif
