/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_destroy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:26:02 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 19:34:51 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_DESTROY_H
# define VEC_DESTROY_H

# define vec_destroy_( self ) \
	vec_destroy(self)

void vec_destroy( void * self );

#endif
