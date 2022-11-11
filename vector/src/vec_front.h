/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_front.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:08:16 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:13:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_FRONT_H
# define VEC_FRONT_H

# define vec_front_( self ) \
	(typeof(*self->data) *)vec_front(self)

# define vec_cfront_( self ) \
	(const typeof(*self->data) *)vec_cfront(self)

void * vec_front( void * self );
const void * vec_cfront( const void * self );

#endif

