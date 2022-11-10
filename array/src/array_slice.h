/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_slice.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:48:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 09:16:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_SLICE_H
# define ARRAY_SLICE_H

# define _array_slice( arr, pos, n ) \
	do {\
		if ((pos) > (arr)->size) \
			array_throw(ARRAY_ERANGE);\
		size_t array_new_size = (n) < (arr)->size - (pos) ?\
			(n) : (arr)->size - (pos);\
		array_memcpy(\
			(arr)->data,\
			(arr)->data + (pos),\
			array_new_size * sizeof(*(arr)->data)\
		);\
		*(size_t *)&(arr)->size = array_new_size;\
	} while (0)

#endif
