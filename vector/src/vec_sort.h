/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:57:52 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:17:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_SORT_H
# define VEC_SORT_H

# define vec_sort_( self, func ) \
	do \
	{ \
		$NOINLINE \
		bool _ PP_PARAM2( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_sort(self, _); \
	} \
	while (0)

void vec_sort( void * self, int (*func)() );

#endif
