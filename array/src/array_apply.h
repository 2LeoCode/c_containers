/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_apply.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:31:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:55:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_APPLY_H
# define ARRAY_APPLY_H

# define _array_apply( arr, app_args, app_body ) \
	do for (\
		typeof(*(arr)->data) * ARRAY_EXPAND_1 app_args = (arr)->data;\
		ARRAY_EXPAND_1 app_args != (arr)->data + (arr)->size;\
		++ARRAY_EXPAND_1 app_args\
	) { ARRAY_EXPAND_N app_body } while (0)

#endif
