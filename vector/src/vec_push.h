/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:01:26 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 19:00:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_PUSH_H
# define VEC_PUSH_H

# define vec_push_back_( self, values... ) \
	do \
	{ \
		const typeof(*self->data) _[] = { values }; \
		vec_push_back(&(self), _, sizeof(_) / sizeof(*_)); \
	} while (0)

# define vec_push_front_( self, values... ) \
	do \
	{ \
		const typeof(*self->data) _[] = { values }; \
		vec_push_front(&(self), _, sizeof(_) / sizeof(*_)); \
	} while (0)

# define vec_push_( self, pos, values... ) \
	do \
	{ \
		const typeof(*self->data) _[] = { values }; \
		vec_push(&(self), pos, values, sizeof(_) / sizeof(*_)); \
	} while (0)

# define vec_push_array_( self, pos, array, n ) \
	vec_push(self, pos, array, n)

void vec_push_back( void * self_ptr, const void * values, size_t n );
void vec_push_front( void * self_ptr, const void * values, size_t n );
void vec_push( void * self_ptr, ptrdiff_t pos, const void * values, size_t n );

#endif
