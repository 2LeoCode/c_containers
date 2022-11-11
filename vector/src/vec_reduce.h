/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reduce.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:41:40 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:17:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_REDUCE_H
# define VEC_REDUCE_H

# define vec_reduce_( self, res_ptr, func ) \
	({ \
		$NOINLINE \
		int _ PP_PARAM3_DIFF( \
			const type *, const type *, type *, PP_EXPAND_PARAM func \
		) PP_EXPAND_BODY func \
		typeof(*self->data) res_; \
		vec_reduce(self, &res_, _); \
		res_; \
	})

# define vec_reduce_range_( self, pos, n, func ) \
	({ \
		$NOINLINE \
		int _ PP_PARAM3_DIFF( \
			const type *, const type *, type *, PP_EXPAND_PARAM func \
		) PP_EXPAND_BODY func \
		typeof(*self->data) res_; \
		vec_reduce_range(self, &res_, pos, n, _); \
		res_; \
	})

void vec_reduce( const void * self, void * res_ptr, int (*func)() );
void vec_reduce_range( const void * self, void * res_ptr, ptrdiff_t pos, size_t n,
	int (*func)() );

#endif
