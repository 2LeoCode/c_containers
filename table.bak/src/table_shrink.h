/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_shrink.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:31:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/18 11:32:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_SHRINK_H
# define TABLE_SHRINK_H

# define _table_shrink( tab ) \
	table_shrink(&(tab))

void table_shrink( void * tab_addr );

#endif
