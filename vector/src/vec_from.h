/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:02:35 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 20:02:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_FROM_H
# define VEC_FROM_H

# define vec_from_( other ) \
	(typeof(other))vec_from(other)

# define vec_from_array_( array, n, cpy_fun, del_fun ) \
	(typeof(*array) *)vec_from_array(sizeof(*array), array, n, cpy_fun, del_fun)

void * vec_from( const void * other );
void * vec_from_array( size_t elem_size, const void * array, size_t n,
	vec_cpy_f * cpy_fun, vec_del_f * del_fun );

#endif
