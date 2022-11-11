/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:31:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/05 23:09:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <stdlib.h>

void * array_memcpy( void * dst, const void * src, size_t n ) {
	return memcpy(dst, src, n);
}

void * array_memmove( void * dst, const void * src, size_t n ) {
	return memmove(dst, src, n);
}

void * array_memset( void * s, int c, size_t n ) {
	return memset(s, c, n);
}

void * array_malloc( size_t size ) {
	return malloc(size);
}

void * array_realloc( void * ptr, size_t size ) {
	return realloc(ptr, size);
}
