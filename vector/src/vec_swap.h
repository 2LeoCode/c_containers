/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:22:19 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:17:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_SWAP_H
# define VEC_SWAP_H

# define vec_swap_( self, other ) \
	vec_swap(&(self), &(other))

# define vec_swap_elements_( self, pos1, other, pos2 ) \
	vec_swap_elements(self, pos1, other, pos2)

# define vec_swap_ranges_( self, pos1, n1, other, pos2, n2 ) \
	vec_swap_ranges(self, pos1, n1, other, pos2, n2)

void vec_swap( void * self_ptr, void * other_ptr );
void vec_swap_elements( void * self, ptrdiff_t pos1, void * other, ptrdiff_t pos2 );
void vec_swap_ranges( void * self, ptrdiff_t pos1, size_t n1, void * other,
	ptrdiff_t pos2, size_t n2 );

#endif
