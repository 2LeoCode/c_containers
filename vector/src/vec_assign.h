/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_assign.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:40:51 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 21:32:58 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ASSIGN_H
# define VEC_ASSIGN_H

# define vec_assign_( self, other ) \
	vec_assign(&(self), other)

# define vec_assign_array_( self, array, n ) \
	vec_assign_array(&(self), array, n)

void vec_assign( void * self_ptr, const void * other );
void vec_assign_array( void * self_ptr, const void * array, size_t n );

#endif
