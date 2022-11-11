/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:54:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:57:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_INSERT_H
# define ARRAY_INSERT_H

# define _array_insert( arr, pos, value ) \
	array_ninsert(arr, pos, (typeof(value)[]){ value }, 1)

#endif
