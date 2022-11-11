/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_count.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:39:40 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:15:39 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_COUNT_H
# define VEC_COUNT_H

# define vec_count_( self, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1(const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_count(self, _); \
	})

# define vec_count_range_( self, pos, n, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1(const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_count_range(self, pos, n, _); \
	})

size_t vec_count( const void * self, bool (*func)() );
size_t vec_count_range( const void * self, ptrdiff_t pos, size_t n,
	bool (*func)() );

#endif
