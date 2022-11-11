/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:48:56 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_POP_H
# define VEC_POP_H

# define vec_pop_back_( self, n ) \
	vec_pop_back(self, n)

# define vec_pop_front_( self, n ) \
	vec_pop_front(self, n)

# define vec_pop_( self, pos, n ) \
	vec_pop(self, pos, n)

void vec_pop_back( void * self, size_t n );
void vec_pop_front( void * self, size_t n );
void vec_pop( void * self, ptrdiff_t pos, size_t n );

#endif
