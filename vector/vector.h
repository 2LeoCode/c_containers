/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:01:23 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 15:19:28 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdbool.h>

# include "src/common/pp_utilities.h"

# define VEC_NPOS -1

typedef int vec_cpy_f();
typedef void vec_del_f();

# include "src/vec_apply.h"
# include "src/vec_assign.h"
# include "src/vec_back.h"
# include "src/vec_clear.h"
# include "src/vec_count.h"
# include "src/vec_cpy_fun.h"
# include "src/vec_del_fun.h"
# include "src/vec_destroy.h"
# include "src/vec_filter.h"
# include "src/vec_find.h"
# include "src/vec_from.h"
# include "src/vec_front.h"
# include "src/vec_iter.h"
# include "src/vec_map.h"
# include "src/vec_new.h"
# include "src/vec_pop.h"
# include "src/vec_push.h"
# include "src/vec_reduce.h"
# include "src/vec_reserve.h"
# include "src/vec_resize.h"
# include "src/vec_shrink.h"
# include "src/vec_slice.h"
# include "src/vec_sort.h"
# include "src/vec_swap.h"

# define vec( type ) \
	struct { \
		const size_t size; \
		const size_t capacity; \
		type data[]; \
	}

# define smart_vec( type ) \
	$SMART(vec) \
	vec(type)

// Constructors

/*	vec(type) * vec_new(
*	... type
*	...	size_t capacity
* 	... vec_cpy_fun * cpy_fun
* 	... vec_del_fun * del_fun
*	); */
# define vec_new( type, cpy_fun, del_fun ) \
	vec_new_( type, cpy_fun, del_fun )

/*	vec(type) * vec_new_with_capacity(
*	...	type
*	...	size_t capacity
* 	... vec_cpy_fun * cpy_fun
* 	... vec_del_fun * del_fun
*	); */
# define vec_new_with_capacity( type, capacity, cpy_fun, del_fun ) \
	vec_new_with_capacity_(type, capacity, cpy_fun, del_fun)

/*	vec(type) * vec_from(
*	...	vec(type) * other
* 	); */
# define vec_from( other ) \
	vec_from_( other )

/* 	vec(type) * vec_from_array(
*	... type * array
*	...	size_t n
* 	); */
# define vec_from_array( array, n, cpy_fun, del_fun ) \
	vec_from_array_(array, n, cp_fun, del_fun)

// Destructor

/*	void vec_destroy(
*	...	vec(type) * self
*	); */
# define vec_destroy( self ) \
	vec_destroy_( self )


// Modifiers

/*	void vec_assign(
*	...	vec(type) * self
*	... vec(type) * other
*	); */
# define vec_assign( self, other ) \
	vec_assign_( self, other )

/*	void vec_assign_array(
*	...	vec(type) * self
*	... type * array
*	...	size_t n
*	); */
# define vec_assign_array( self, array, n ) \
	vec_assign_array_( self, array, n )

/*	void vec_push_back(
*	...	vec(type) * self
*	... type values...
*	); */
# define vec_push_back( self, values... ) \
	vec_push_back_( self, values )

/*	void vec_push_front(
*	...	vec(type) * self
*	... type values...
*	); */
# define vec_push_front( self, values... ) \
	vec_push_front_( self, values )

/*	void vec_push(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... type values...
*	); */
# define vec_push( self, pos, values... ) \
	vec_push_( self, pos, values )

/*	void vec_push_array(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... type * array
*	...	size_t n
*	); */
# define vec_push_array( self, pos, array, n ) \
	vec_push_array_( self, pos, array, n )


/*	void vec_pop_back(
*	...	vec(type) * self
*	); */
# define vec_pop_back( self, n ) \
	vec_pop_back_( self, n )

/*	void vec_pop_front(
*	...	vec(type) * self
*	... size_t n
*	); */
# define vec_pop_front( self, n ) \
	vec_pop_front_( self, n )

/*	void vec_pop(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	); */
# define vec_pop( self, pos, n ) \
	vec_pop_( self, pos, n )

/*	void vec_clear(
*	...	vec(type) * self
*	); */
# define vec_clear( self ) \
	vec_clear_( self )

/*	void vec_resize(
*	...	vec(type) * self
*	... size_t n
*	... type value
*	); */
# define vec_resize( self, n, value ) \
	vec_resize_( self, n, value )

/*	void vec_reserve(
*	...	vec(type) * self
*	... size_t n
*	); */
# define vec_reserve( self, n ) \
	vec_reserve_( self, n )

/*	void vec_shrink(
*	...	vec(type) * self
*	); */
# define vec_shrink( self ) \
	vec_shrink_( self )

/*	void vec_swap(
*	...	vec(type) * self
*	... vec(type) * other
*	); */
# define vec_swap( self, other ) \
	vec_swap_( self, other )

/*	void vec_swap_elements(
*	...	vec(type) * self
*	... ptrdiff_t pos1
*	... vec(type) * other
*	... ptrdiff_t pos2
*	); */
# define vec_swap_elements( self, pos1, other, pos2 ) \
	vec_swap_elements_( self, pos1, other, pos2 )

/*	void vec_swap_ranges(
*	...	vec(type) * self
*	... ptrdiff_t pos1
*	...	size_t n1
*	... vec(type) * other
*	... ptrdiff_t pos2
*	... size_t n2
*	); */
# define vec_swap_ranges( self, pos1, n1, other, pos2, n2 ) \
	vec_swap_ranges_( self, pos1, n1, other, pos2, n2 )

/*	void vec_apply(
*	...	vec(type) * self
*	... (type *)({...}) -> void
*	); */
# define vec_apply( self, func ) \
	vec_apply_( self, func )

/*	void vec_apply_range(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (type *)({...}) -> void
*	); */
# define vec_apply_range( self, pos, n, func ) \
	vec_apply_range_( self, pos, n, func )

/*	void vec_rapply(
*	...	vec(type) * self
*	... (type *)({...}) -> void
*	); */
# define vec_rapply( self, func ) \
	vec_rapply_( self, func )

/*	void vec_rapply_range(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (type *)({...}) -> void
*	); */
# define vec_rapply_range( self, pos, n, func ) \
	vec_rapply_range_( self, pos, n, func )

/*	void vec_filter(
*	...	vec(type) * self
*	... (const type *)({...}) -> bool
*	); */
# define vec_filter( self, func ) \
	vec_filter_( self, func )

/*	void vec_filter_range(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *)({...}) -> bool
*	); */
# define vec_filter_range( self, pos, n, func ) \
	vec_filter_range_( self, pos, n, func )

/*	vec(type) * vec_slice(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	); */
# define vec_slice( self, pos, n ) \
	vec_slice_( self, pos, n )

/*	void vec_reverse(
*	...	vec(type) * self
*	); */
# define vec_reverse( self ) \
	vec_reverse_( self )

/*	void vec_reverse_range(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	); */
# define vec_reverse_range( self, pos, n ) \
	vec_reverse_range_( self, pos, n )

/*	void vec_sort(
*	...	vec(type) * self
*	... (const type *, const type *)({...}) -> int
*	); */
# define vec_sort( self, func ) \
	vec_sort_( self, func )


// Element access

/*	type * vec_front(
*	...	vec(type) * self
*	); */
# define vec_front( self ) \
	vec_front_( self )

/*	const type * vec_cfront(
*	...	const vec(type) * self
*	); */
# define vec_cfront( self ) \
	vec_cfront_( self )

/*	type * vec_back(
*	...	vec(type) * self
*	); */
# define vec_back( self ) \
	vec_back_( self )

/*	const type * vec_cback(
*	...	const vec(type) * self
*	); */
# define vec_cback( self ) \
	vec_cback_( self )

/*	vec_cpy_f * vec_cpy_fun(
*	...	vec(type) * self
*	); */
# define vec_cpy_fun( self ) \
	vec_cpy_fun_( self )

/*	vec_del_f * vec_del_fun(
*	...	vec(type) * self
*	); */
# define vec_del_fun( self ) \
	vec_del_fun_( self )

/*	void vec_iter(
*	...	const vec(type) * self
*	... (const type *)({...}) -> void
*	); */
# define vec_iter( self, func ) \
	vec_iter_( self, func )

/*	void vec_iter_range(
*	...	const vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *)({...}) -> void
*	); */
# define vec_iter_range( self, pos, n, func ) \
	vec_iter_range_( self, pos, n, func )

/*	void vec_riter(
*	...	const vec(type) * self
*	... (const type *)({...}) -> void
*	); */
# define vec_riter( self, func ) \
	vec_riter_( self, func )

/*	void vec_riter_range(
*	...	const vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *)({...}) -> void
*	); */
# define vec_riter_range( self, pos, n, func ) \
	vec_riter_range_( self, pos, n, func )

/*	ptrdiff_t vec_find(
*	...	const vec(type) * self
*	... (const type *)({...}) -> bool
*	); */
# define vec_find( self, func ) \
	vec_find_( self, func )

/*	ptrdiff_t vec_find_from(
*	...	const vec(type) * self
*	... ptrdiff_t pos
*	... (const type *)({...}) -> bool
*	); */
# define vec_find_from( self, pos, func ) \
	vec_find_from_( self, pos, func )

/*	ptrdiff_t vec_find_range(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *)({...}) -> bool
*	); */
# define vec_find_range( self, pos, n, func ) \
	vec_find_range_( self, pos, n, func )

/*	ptrdiff_t vec_rfind(
*	...	vec(type) * self
*	... (const type *)({...}) -> bool
*	); */
# define vec_rfind( self, func ) \
	vec_rfind_( self, func )

/*	ptrdiff_t vec_rfind_from(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... (const type *)({...}) -> bool
*	); */
# define vec_rfind_from( self, pos, func ) \
	vec_rfind_from_( self, pos, func )

/*	ptrdiff_t vec_rfind_range(
*	...	vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *)({...}) -> bool
*	); */
# define vec_rfind_range( self, pos, n, func ) \
	vec_rfind_range_( self, pos, n, func )

/*	size_t vec_count(
*	...	const vec(type) * self
*	... (const type *)({...}) -> bool
*	); */
# define vec_count( self, func ) \
	vec_count_( self, func )

/*	size_t vec_count_range(
*	...	const vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *)({...}) -> bool
*	); */
# define vec_count_range( self, pos, n, func ) \
	vec_count_range_( self, pos, n, func )


// Mapping

/*	vec(type2) vec_map(
*	...	const vec(type) * self
*	...	type2
*	... (const type *, type2 *)({...}) -> int
*	... vec_cpy_f * cpy_fun
*	... vec_del_f * del_fun
*	); */
# define vec_map( self, type2, func, cpy_fun, del_fun ) \
	vec_map_( self, type2, func, cpy_fun, del_fun )

/*	vec(type2) vec_map_range(
*	...	const vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... type2
*	... (const type *, type2 *)({...}) -> int
*	... vec_cpy_f * cpy_fun
*	... vec_del_f * del_fun
*	); */
# define vec_map_range( self, pos, n, type2, func, cpy_fun, del_fun ) \
	vec_map_range_( self, pos, n, type2, func, cpy_fun, del_fun )

/*	type vec_reduce(
*	...	const vec(type) * self
*	... (const type *, const type *, type *)({...}) -> int
*	); */
# define vec_reduce( self, func ) \
	vec_reduce_( self, func )

/*	type vec_reduce_range(
*	...	const vec(type) * self
*	... ptrdiff_t pos
*	... size_t n
*	... (const type *, const type *, type *)({...}) -> int
*	); */
# define vec_reduce_range( self, pos, n, func ) \
	vec_reduce_range_( self, pos, n, func )

#endif
