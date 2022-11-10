/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_apply.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:20:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:45:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_APPLY_H
# define TABLE_APPLY_H

# define _table_apply( tab, apply_expr ) \
	do\
	{\
		$NOINLINE\
		void _ PP_PARAM1(typeof(tab), PP_EXPAND_PARAM apply_expr)\
		PP_EXPAND_BODY apply_expr\
		table_apply(tab, _);\
	}\
	while (0)

# define _table_iter( tab, iter_expr ) \
	do\
	{\
		$NOINLINE\
		void _ PP_PARAM1(const typeof(*(tab)) *, PP_EXPAND_PARAM iter_expr)\
		PP_EXPAND_BODY iter_expr\
		(table_apply)(tab, _);\
	}\
	while (0)

void table_apply( void * tab, void (*app_fun)() );

#endif
