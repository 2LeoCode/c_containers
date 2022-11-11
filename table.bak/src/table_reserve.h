/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_reserve.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:49:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/17 22:08:38 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_RESERVE_H
# define TABLE_RESERVE_H

# define _table_reserve( tab, n ) \
	table_reserve(&(tab), n)



void table_reserve( void * tab_addr, size_t n );

#endif
