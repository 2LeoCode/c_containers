/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_iter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:14:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:57:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_ITER_H
# define ARRAY_ITER_H

# define _array_iter( arr, ite_args, ite_body ) \
	do for (\
		typeof(*(arr)->data) * array_iterator = (arr)->data;\
		array_iterator != (arr)->data + (arr)->size;\
		++array_iterator\
	) {\
		typeof(*(arr)->data) ARRAY_EXPAND_1 ite_args = *array_iterator;\
		ARRAY_EXPAND_N ite_body\
	} while (0)

#endif
