/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cpy_fun.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:18:07 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:19:31 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_CPY_FUN_H
# define VEC_CPY_FUN_H

# define vec_cpy_fun_( self ) \
	vec_cpy_fun(self)

vec_cpy_f * vec_cpy_fun( const void * self );

#endif
