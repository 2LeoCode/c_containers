/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:43:29 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 20:01:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_NEW_H
# define VEC_NEW_H

# define vec_new_( type, cpy_fun, del_fun ) \
	(vec(type) *)vec_new(sizeof(type), cpy_fun, del_fun)

# define vec_new_with_capacity_( type, capacity, cpy_fun, del_fun ) \
	(vec(type) *)vec_new_with_capacity(sizeof(type), capacity, cpy_fun, del_fun)

void * vec_new( size_t elem_size, vec_cpy_f * cpy_fun, vec_del_f * del_fun );

void * vec_new_with_capacity( size_t elem_size, size_t capacity,
	vec_cpy_f * cpy_fun, vec_del_f * del_fun );

#endif
