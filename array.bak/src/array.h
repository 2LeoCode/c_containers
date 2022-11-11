/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:31:38 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 09:30:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>
# include <setjmp.h>

# include "array_utils.h"
# include "array_pp.h"

# include "array_init.h"
# include "array_new.h"
# include "array_destroy.h"

# include "array_status.h"
# include "array_throw.h"

# include "array_reserve.h"

# include "array_ninsert.h"
# include "array_insert.h"
# include "array_push.h"

# include "array_nremove.h"
# include "array_remove.h"
# include "array_pop.h"

# include "array_apply.h"
# include "array_rapply.h"
# include "array_iter.h"
# include "array_riter.h"
# include "array_filter.h"
# include "array_sort.h"
# include "array_slice.h"
# include "array_rslice.h"

# define ARRAY_OK 0
# define ARRAY_ENOMEM 1
# define ARRAY_ERANGE 2

extern jmp_buf array_errbuf;
extern int array_errno;

# define array( type ) \
	typeof(\
		struct {\
			const size_t size;\
			const size_t capacity;\
			type data[];\
		} * const\
	)



# define array_status( ) \
	_array_status()

# define array_throw( errnum ) \
	_array_throw(errnum)



# define array_new( type, name ) \
	_array_new(type, name)

# define array_init( arr ) \
	_array_init(arr)



# define array_reserve( arr, new_cap ) \
	_array_reserve(arr, new_cap)



# define array_ninsert( arr, pos, values, n ) \
	_array_ninsert(arr, pos, values, n)

# define array_insert( arr, pos, value ) \
	_array_insert(arr, pos, value)

# define array_push( arr, value ) \
	_array_push(arr, value)



# define array_nremove( arr, pos, n ) \
	_array_nremove(arr, pos, n)

# define array_remove( arr, pos ) \
	_array_remove(arr, pos)

# define array_pop( arr ) \
	_array_pop(arr)



/*
 *  app: (type *) => void
 */
# define array_apply( arr, app_args, app_body ) \
	_array_apply(arr, app_args, app_body)

/*
 *  app: (type *) => void
 */
# define array_rapply( arr, app_args, app_body ) \
	_array_rapply(arr, app_args, app_body)

/*
 *  ite: (type) => void
 */
# define array_iter( arr, ite_args, ite_body ) \
	_array_iter(arr, ite_args, ite_body)

/*
 *  ite: (type) => void
 */
# define array_riter( arr, ite_args, ite_body ) \
	_array_riter(arr, ite_args, ite_body)



/*
 *  cnd: (type) => bool
 */
# define array_filter( arr, cnd_args, cnd_body ) \
	_array_filter(arr, cnd_args, cnd_body )

/*
 *  cmp: (type, type) => int
 */
# define array_sort( arr, cmp_args, cmp_body ) \
	_array_sort(arr, cmp_args, cmp_body)

# define array_slice( arr, pos, n ) \
	_array_slice(arr, pos, n)

# define array_rslice( arr, pos, n ) \
	_array_rslice(arr, pos, n)

# define array_reverse( arr ) \
	_array_reverse(arr)


/*
 *  map: (type) => type *
 */
# define array_map( dst, src, map_args, map_body ) \
	_array_map(dst, src, map_args, map_body)

/*
 *  cnd: (type) => bool
 *  map: (type) => type *
 */
# define array_filtermap( dst, src, cnd_args, cnd_body, map_args, map_body ) \
	_array_filtermap(dst, src, cnd_args, cnd_body, map_args, map_body)

/*
 *  cmp: (type, type) => int
 *  map: (type) => type *
 */
# define array_sortmap( dst, src, cmp_args, cmp_body, map_args, map_body ) \
	_array_sortmap(dst, src, cmp_args, cmp_body)

# define array_slicemap( dst, src, pos, n ) \
	_array_slicemap(dst, src, pos, n)

# define array_rslicemap( dst, src, pos, n ) \
	_array_rslicemap(dst, src, pos, n)

# define array_reversemap( dst, src ) \
	_array_reversemap(dst, src)


/*
 *  red: (type, type) => type
 */
# define array_reduce( arr, red_args, red_body ) \
	_array_reduce(arr, red_args, red_body)



/*
 *  cnd: (type) => bool
 */
# define array_find( arr, cnd_args, cnd_body ) \
	_array_find(arr, cnd_args, cnd_body)

/*
 *  cnd: (type) => bool
 */
# define array_rfind( arr, cnd_args, cnd_body ) \
	_array_rfind(arr, cnd_args, cnd_body)



# define array_destroy( arr ) \
	_array_destroy()

#endif
