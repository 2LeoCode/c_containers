/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:14:44 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 17:58:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INT_H
# define VECTOR_INT_H

# include "../vector.h"
# include "error/error.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_vec_int t_vec_int;

struct s_vec_int
{
	size_t		elem_size;
	vec_cpy_f *	cpy_fun;
	vec_del_f *	del_fun;
	size_t		size;
	size_t		capacity;
	uint8_t		data[];
};

t_vec_int * get_vec_int( void * vec );
const t_vec_int * get_const_vec_int( const void * vec );

#endif
