/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_utilities.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:06:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 15:14:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_UTILITIES_H
# define PP_UTILITIES_H

# define PP_VOID( X... )

# define PP_EXPAND( X... ) \
	X

# define PP_PARAM1( type, X ) \
	(type X)

# define PP_PARAM2( type, args... ) \
	_PP_PARAM2(type, args)

# define _PP_PARAM2( type, X, Y ) \
	(type X, type Y)

# define PP_EXPAND_PARAM( expr... ) \
	expr PP_VOID

# define PP_EXPAND_BODY( expr... ) \
	PP_VOID(expr) PP_EXPAND

#endif
