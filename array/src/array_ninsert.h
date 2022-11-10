/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ninsert.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:03:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:57:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_NINSERT
# define ARRAY_NINSERT

# define _array_ninsert( arr, pos, values, n ) \
	do {\
		if (!(n))\
			break ;\
		if ((pos) > (arr)->size)\
			array_throw(ARRAY_ERANGE);\
		if ((arr)->size + (n) > (arr)->capacity) {\
			if ((n) < (arr)->size)\
				array_reserve(arr, (arr)->size * 2);\
			else\
				array_reserve(arr, (arr)->size + n);\
		}\
		array_memmove(\
			(arr)->data + pos + n,\
			(arr)->data + pos,\
			sizeof(*(arr)->data) * ((arr)->size - pos)\
		);\
		array_memcpy(\
			(arr)->data + pos,\
			values,\
			sizeof(*(arr)->data) * n\
		);\
		*(size_t *)&(arr)->size += (n);\
	} while (0)

#endif
