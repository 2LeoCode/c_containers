/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_back.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:15:55 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:16:11 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_BACK_H
# define VEC_BACK_H

# define vec_back_( self ) \
	(typeof(*self->data) *)vec_back(self)

# define vec_cback_( self ) \
	(const typeof(*self->data) *)vec_cback(self)

void * vec_back( void * self );
const void * vec_cback( const void * self );

#endif
