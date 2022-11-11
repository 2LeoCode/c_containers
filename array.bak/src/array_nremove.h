/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_nremove.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:09:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:57:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_NREMOVE_H
# define ARRAY_NREMOVE_H

# define _array_nremove( arr, pos, n ) \
	do {\
		if (!(n))\
			break ;\
		if ((pos) >= (arr)->size)\
			array_throw(ARRAY_ERANGE);\
		if ((n) < (arr)->size - (pos)) {\
			array_memcpy(\
				(arr)->data + (pos),\
				(arr)->data + (pos) + (n),\
				sizeof(*(arr)->data) * ((arr)->size - (pos) - (n))\
			);\
			*(size_t *)&(arr)->size -= (n);\
		} else\
			*(size_t *)&(arr)->size -= (arr)->size - (pos);\
	} while (0)

#endif
