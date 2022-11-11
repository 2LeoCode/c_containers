/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_apply.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:35:58 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:14:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_APPLY_H
# define VEC_APPLY_H

# define vec_apply_( self, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(typeof(self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_apply(self, _); \
	} \
	while (0)

# define vec_apply_range_( self, pos, n, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(typeof(self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_apply_range(self, pos, n, _); \
	} \
	while (0)

# define vec_rapply_( self, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(typeof(self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_rapply(self, _); \
	} \
	while (0)

# define vec_rapply_range_( self, pos, n, func ) \
	do \
	{ \
		$NOINLINE \
		void _ PP_PARAM1(typeof(self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_rapply_range(self, pos, n, _); \
	} \
	while (0)

void vec_apply( void * self, void (*func)() );
void vec_apply_range( void * self, ptrdiff_t pos, size_t n, void (*func)() );
void vec_rapply( void * self, void (*func)() );
void vec_rapply_range( void * self, ptrdiff_t pos, size_t n, void (*func)() );

#endif
