/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:33 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 11:59:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_RESIZE_H
# define VEC_RESIZE_H

# define vec_resize_( self, n, value ) \
	vec_resize(&(self), n, (const typeof(*self->data)[]){ value })

void vec_resize( void * self_ptr, size_t n, const void * value );

#endif
