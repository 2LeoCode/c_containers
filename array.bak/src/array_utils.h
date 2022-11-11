/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:35:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 09:29:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

# include <stddef.h>

void * array_memcpy( void * dst, const void * src, size_t n );
void * array_memmove( void * dst, const void * src, size_t n );
void * array_memset( void * s, int c, size_t n );
void * array_malloc( size_t size );
void * array_realloc( void * ptr, size_t size );

#endif
