/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:20:58 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:16:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITER_H
# define VEC_ITER_H

# define vec_iter_( self, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(const typeof(*self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_iter(self, _); \
	} \
	while (0)

# define vec_iter_range_( self, pos, n, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(const typeof(*self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_iter_range(self, pos, n, _); \
	} \
	while (0)

# define vec_riter_( self, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(const typeof(*self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_riter(self, _); \
	} \
	while (0)

# define vec_riter_range_( self, pos, n, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(const typeof(*self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_riter_range(self, pos, n, _); \
	} \
	while (0)

void vec_iter( const void * self, void (*func)() );
void vec_iter_range( const void * self, ptrdiff_t pos, size_t n, void (*func)() );
void vec_riter( const void * self, void (*func)() );
void vec_riter_range( const void * self, ptrdiff_t pos, size_t n, void (*func)() );

#endif
