/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_resize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:56:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:08:16 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_RESIZE_H
# define TABLE_RESIZE_H

# define _table_resize( tab, n ) \
	table_resize(&(tab), n)

void table_resize( void * arr_addr, size_t n );

#endif
