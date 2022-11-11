/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_new.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:53:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/18 11:47:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_NEW_H
# define TABLE_NEW_H

# define _table_new( type, cpy_fun__clr_fun... ) \
	({\
		void * _[] = { NULL, ## cpy_fun__clr_fun, NULL, NULL };\
		(table(type))table_new(sizeof(type),\
			_[1], _[2]);\
	})

# define _table_from( other ) \
	(typeof(other))table_from(other)



void * table_new( size_t elemsize, void * cpy_fun, void * clr_fun );

void * table_from( const void * other );

#endif
