/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reverse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:23:36 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_REVERSE_H
# define VEC_REVERSE_H

# define vec_reverse_( self ) \
	vec_reverse(self)

# define vec_reverse_range_( self, pos, n ) \
	vec_reverse_range(self, pos, n)

void vec_reverse( void * self );
void vec_reverse_range( void * self, ptrdiff_t pos, size_t n );

#endif
