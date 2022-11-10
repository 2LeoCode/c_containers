/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_reduce.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:16:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 18:29:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_REDUCE_H
# define TABLE_REDUCE_H

# define _table_reduce( tab, reduce_expr ) \
	({\
		typeof(*(tab)) ret;\
		typeof(*(tab)) tmp;\
		$NOINLINE\
		typeof(*(tab)) _ PP_PARAM2(const typeof(*(tab)) *,\
			PP_EXPAND_PARAM reduce_expr)\
		PP_EXPAND_BODY reduce_expr\
		if (!table_cpy_fun(tab))\
			ret = (tab)[0];\
		else if (table_cpy_fun(tab)(&ret, tab))\
			table_break(ENOMEM);\
		for (size_t i = 1; i < table_size(tab); ++i)\
		{\
			tmp = _(&ret, tab + i);\
			if (table_clr_fun(tab))\
				table_clr_fun(tab)(&ret);\
			ret = tmp;\
		}\
		ret;\
	})

#endif
