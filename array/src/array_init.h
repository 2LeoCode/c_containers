/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:39:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:57:19 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_INIT_H
# define ARRAY_INIT_H

# define _array_init( arr ) \
	do {\
		*(void **)&(arr) = array_malloc(sizeof(*(arr)));\
		if (!(arr))\
			array_throw(ARRAY_ENOMEM);\
		array_memset((void *)(arr), 0, sizeof(*(arr)));\
	} while (0)

#endif
