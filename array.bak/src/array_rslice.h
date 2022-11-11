/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_rslice.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:03:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 09:16:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_RSLICE_H
# define ARRAY_RSLICE_H

# define _array_rslice( arr, pos, n ) \
	do {\
		if ((pos) > (arr)->size) \
			array_throw(ARRAY_ERANGE);\
		if ((n) < (pos) + 1)\
\
		size_t array_new_size = (n) < (pos) + 1 ?\
			(n) : (pos) + 1;\
		array_memcpy(\
			(arr)->data,\
			(arr)->data + (pos) - (array_new_size - 1),\
			array_new_size * sizeof(*(arr)->data)\
		);\
		*(size_t *)&(arr)->size = array_new_size;\
	} while (0)

#endif
