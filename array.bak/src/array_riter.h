/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_riter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:47:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_RITER_H
# define ARRAY_RITER_H

# define _array_riter( arr, ite_args, ite_body ) \
	do for (\
		typeof(*(arr)->data) * array_iterator = (arr)->data + (arr)->size - 1;\
		array_iterator != (arr)->data - 1;\
		--array_iterator\
	) {\
		typeof(*(arr)->data) ARRAY_EXPAND_1 ite_args = *array_iterator;\
		ARRAY_EXPAND_N ite_body\
	} while (0)

#endif
