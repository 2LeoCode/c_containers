/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_rapply.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:45:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:58:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_RAPPLY_H
# define ARRAY_RAPPLY_H

# define _array_rapply( arr, app_args, app_body ) \
	do for (\
		typeof(*(arr)->data) * ARRAY_EXPAND_1 app_args\
			= (arr)->data + (arr)->size - 1;\
		ARRAY_EXPAND_1 app_args != (arr)->data - 1;\
		--ARRAY_EXPAND_1 app_args\
	) { ARRAY_EXPAND_N app_body } while (0)

#endif
