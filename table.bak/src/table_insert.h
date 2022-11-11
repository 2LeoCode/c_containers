/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_insert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:21:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/18 17:30:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_INSERT_H
# define TABLE_INSERT_H

# define _table_insert( tab, pos, data... ) \
	do\
	{\
		typeof(*(tab)) _[] = { data };\
		table_insert_n(tab, pos, _, sizeof(_) / sizeof(*_));\
	}\
	while (0)

# define _table_insert_n( tab, pos, data_ptr, n ) \
	(table_insert)(&(tab), pos, data_ptr, n)

# define _table_push( tab, data... ) \
	table_insert(tab, table_size(tab), data)

# define _table_push_n( tab, data_ptr, n ) \
	table_insert_n(tab, table_size(tab), data_ptr, n)



void table_insert( void * tab_addr, ptrdiff_t pos, const void * data, size_t n );

#endif
