/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:48:40 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:16:39 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_MAP_H
# define VEC_MAP_H

# define vec_map_( self, type2, func, cpy_fun, del_fun ) \
	(vec(type2) *)({ \
		$NOINLINE \
		int _ PP_PARAM2_DIFF(const type *, type2 *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_map(self, sizeof(type2), _, cpy_fun, del_fun); \
	})

# define vec_map_range_( self, pos, n, type2, func, cpy_fun, del_fun ) \
	(vec(type2) *)({ \
		$NOINLINE \
		int _ PP_PARAM2_DIFF(const type *, type2 *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_map_range(self, sizeof(type2), pos, n, _, cpy_fun, del_fun); \
	})

void * vec_map( const void * self, size_t new_elem_size, int (*func)(),
	vec_cpy_f * cpy_fun, vec_del_f * del_fun );
void * vec_map_range( const void * self, size_t new_elem_size,
	ptrdiff_t pos, size_t n, int (*func)(), vec_cpy_f * cpy_fun,
	vec_del_f * del_fun );

#endif
