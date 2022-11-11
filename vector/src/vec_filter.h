/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_filter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:42:47 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:31:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_FILTER_H
# define VEC_FILTER_H

# define vec_filter_( self, func ) \
	do \
	{ \
		$NOINLINE \
		bool _ PP_PARAM1(const typeof(self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_filter(self, _); \
	} \
	while (0)

# define vec_filter_range_( self, pos, n, func ) \
	do \
	{ \
		$NOINLINE \
		bool _ PP_PARAM1(const typeof(self->data) *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_filter_range(self, pos, n, _); \
	} \
	while (0)

void vec_filter( void * self, bool (*func)() );
void vec_filter_range( void * self, ptrdiff_t pos, size_t n, bool (*func)() );

#endif
