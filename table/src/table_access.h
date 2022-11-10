/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_access.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:23:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:50:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_ACCESS_H
# define TABLE_ACCESS_H

typedef int cpy_f();
typedef void clr_f();

# define _table_size( tab ) \
	table_size(tab)

# define _table_capacity( tab ) \
	table_capacity(tab)

# define _table_empty( tab ) \
	!table_size(tab)

# define _table_front( tab ) \
	*(tab)

# define _table_back( tab ) \
	(tab)[table_size(tab) - 1]

# define _table_cpy_fun( tab ) \
	table_cpy_fun(tab)

# define _table_clr_fun( tab ) \
	table_clr_fun(tab)


size_t table_size( const void * tab );

size_t table_capacity( const void * tab );

cpy_f * table_cpy_fun( const void * tab );

clr_f * table_clr_fun( const void * tab );


#endif
