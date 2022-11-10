/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_slice.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:59:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/19 16:07:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_SLICE_H
# define TABLE_SLICE_H

# define _table_slice( tab, pos, n ) \
	table_slice(tab, pos, n)

void table_slice( void * tab, ptrdiff_t pos, size_t n );

#endif
