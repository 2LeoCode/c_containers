/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_assign.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:00:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 14:04:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_ASSIGN_H
# define TABLE_ASSIGN_H

# define _table_assign( tab, other ) \
	(typeof(other))table_assign(&(tab), other)



void * table_assign( void * tab_addr, const void * other );

#endif
