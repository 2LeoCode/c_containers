/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_filter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:22:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:44:42 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_FILTER_H
# define TABLE_FILTER_H

# define _table_filter( tab, cnd_expr ) \
	do\
	{\
		$NOINLINE\
		bool _ PP_PARAM1(const typeof(*(tab)) *, PP_EXPAND_PARAM cnd_expr)\
		PP_EXPAND_BODY cnd_expr\
		table_filter(tab, _);\
	}\
	while (0)



void table_filter( void * tab, bool (*cnd_fun)() );

#endif
