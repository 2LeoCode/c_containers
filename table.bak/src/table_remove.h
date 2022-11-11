/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_remove.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:51:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/12 19:39:55 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_REMOVE_H
# define TABLE_REMOVE_H

# define _table_remove( tab, pos, n ) \
	table_remove(tab, pos, n)

# define _table_pop(tab, n) \
	table_remove(tab, table_size(tab) - n, n)



void table_remove( void * tab, ptrdiff_t pos, size_t n );

#endif
