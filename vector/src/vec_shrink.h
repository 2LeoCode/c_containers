/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_shrink.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:19:30 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 12:19:52 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_SHRINK_H
# define VEC_SHRINK_H

# define vec_shrink_( self ) \
	vec_shrink(&(self))

void vec_shrink( void * self_ptr );

#endif
