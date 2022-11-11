/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_slice.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:06 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_SLICE_H
# define VEC_SLICE_H

# define vec_slice_( self, pos, n ) \
	(typeof(self))vec_slice(self, pos, n)

void * vec_slice( void * self, ptrdiff_t pos, size_t n );

#endif
