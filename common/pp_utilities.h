/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_utilities.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:06:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/11 22:54:41 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_UTILITIES_H
# define PP_UTILITIES_H

# define PP_VOID( ... )

# define PP_EXPAND( X... ) \
	X

# define PP_PARAM1( type, X ) \
	(type X)

# define PP_PARAM2( type, args... ) \
	_PP_PARAM2(type, args)

# define PP_PARAM2_DIFF( type1, type2, args... ) \
	_PP_PARAM2_DIFF(type1, type2, args)

# define PP_PARAM3( type, args... ) \
	_PP_PARAM3(type, args)

# define PP_PARAM3_DIFF( type1, type2, type3, args... ) \
	_PP_PARAM3_DIFF(type1, type2, type3, args)

# define _PP_PARAM2( type, X, Y ) \
	(type X, type Y)

# define _PP_PARAM2_DIFF( type1, type2, X, Y ) \
	(type1 X, type2 Y)

# define _PP_PARAM3( type, X, Y, Z ) \
	(type X, type Y, type Z)

# define _PP_PARAM3_DIFF( type1, type2, type3, X, Y, Z ) \
	(type1 X, type2 Y, type3 Z)

# define PP_EXPAND_PARAM( expr... ) \
	expr PP_VOID

# define PP_EXPAND_BODY( expr... ) \
	PP_VOID(expr) PP_EXPAND

#endif
