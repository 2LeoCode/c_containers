/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_reserve.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:50:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:58:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_RESERVE_H
# define ARRAY_RESERVE_H

# define _array_reserve( arr, new_cap ) \
	do {\
		if ((new_cap) <= (arr)->capacity)\
			break ;\
		void * array_tmp = array_realloc(\
			arr,\
			sizeof(*(arr)) + (new_cap) * sizeof(*(arr)->data)\
		);\
		if (!array_tmp)\
			array_throw(ARRAY_ENOMEM);\
		*(void **)&(arr) = array_tmp;\
		*(size_t *)&(arr)->capacity = (new_cap);\
	} while (0)

#endif
