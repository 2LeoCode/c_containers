/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_filter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:48:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:57:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_FILTER_H
# define ARRAY_FILTER_H

# define _array_filter( arr, cnd_args, cnd_body ) \
	do for (\
		const typeof(*(arr)->data) * array_iterator = (arr)->data;\
		array_iterator != (arr)->data + (arr)->size;\
		++array_iterator\
	) {\
		typeof(*(arr)->data) ARRAY_EXPAND_1 cnd_args = *array_iterator;\
		if (!(ARRAY_EXPAND_N cnd_body)) {\
			array_remove(arr, array_iterator - (arr)->data);\
			--array_iterator;\
		}\
	} while (0)

#endif
