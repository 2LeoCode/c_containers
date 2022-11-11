/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:19:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:44:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_SORT_H
# define TABLE_SORT_H

# define _table_sort( tab, cmp_expr ) \
	do\
	{\
		$NOINLINE\
		int _ PP_PARAM2(const typeof(*(tab)) *, PP_EXPAND_PARAM cmp_expr)\
		PP_EXPAND_BODY cmp_expr\
		table_sort(tab, _);\
	}\
	while (0)

void table_sort( void * tab, int (* cmp_fun)() );

#endif
