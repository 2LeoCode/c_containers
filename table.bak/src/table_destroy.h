/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_destroy.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:57:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 13:59:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_DESTROY_H
# define TABLE_DESTROY_H

# define _table_destroy( tab ) \
	table_destroy(&(tab))



void table_destroy( void * tab );

#endif
