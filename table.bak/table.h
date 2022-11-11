/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:14:42 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 14:56:58 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stddef.h>
# include <stdbool.h>
# include <errno.h>

# include "src/common/attribute_decorators.h"
# include "src/common/helper_types.h"
# include "src/common/pp_utilities.h"

# include "src/table_new.h"
# include "src/table_access.h"
# include "src/table_destroy.h"
# include "src/table_assign.h"
# include "src/table_insert.h"
# include "src/table_remove.h"
# include "src/table_clear.h"
# include "src/table_break.h"
# include "src/table_reserve.h"
# include "src/table_resize.h"
# include "src/table_shrink.h"
# include "src/table_apply.h"
# include "src/table_filter.h"
# include "src/table_sort.h"
# include "src/table_slice.h"
# include "src/table_reduce.h"

// Debug
# include <stdio.h>
// *****

typedef int cpy_f();
typedef void clr_f();

# define table( type ) \
	typeof(type *)

# define const_table( type ) \
	typeof(const type *)

# define smart_table( type ) \
	$SMART(table)\
	table(type)

# define const_smart_table(type) \
	$SMART(table)\
	const_table(type)

/*	table(type) table_new(
*	...	type,
*	...	int (* cpy_fun)( type *, const type * ) = NULL,
*	...	void (* clr_fun)( type * ) = NULL
*	); */ 
# define table_new( type, cpy_fun__clr_fun... ) \
	_table_new(type, ## cpy_fun__clr_fun)

/*	table(T) table_from(
*	...	const table(T) other
*	); */
# define table_from( other ) \
	_table_from(other)


/*	void table_destroy(
*	...	table(T) tab
*	); */
# define table_destroy( tab ) \
	_table_destroy(tab)


/*	size_t table_size(
*	...	const table(T) tab
*	); */
# define table_size( tab ) \
	_table_size(tab)

/*	size_t table_capacity(
*	...	const table(T) tab
*	);*/
# define table_capacity( tab ) \
	_table_capacity(tab)

/*	size_t table_empty(
*	...	const table(T) tab
*	);*/
# define table_empty( tab ) \
	_table_empty(tab)

/*	T table_front(
*	...	table(T) tab
*	); (note: returns a lvalue) */
# define table_front( tab ) \
	_table_front(tab)

/*	T table_back(
*	...	table(T) tab
*	); (note: returns a lvalue) */
# define table_back( tab ) \
	_table_back(tab)

/*	cpy_f * table_cpy_fun(
*	...	const table(T) tab
*	); */
# define table_cpy_fun( tab ) \
	_table_cpy_fun(tab)

/*	clr_f * table_clr_fun(
*	...	const table(T) tab
*	); */
# define table_clr_fun( tab ) \
	_table_clr_fun(tab)



/*	table(U) table_assign(
*	...	table(T) dst,
*	...	const table(U) src 
*	); */
# define table_assign( tab, other ) \
	_table_assign(tab, other)


/*	void table_insert(
*	...	table(T) tab,
*	...	ptrdiff_t pos,
*	...	T data...
*	); */
# define table_insert( tab, pos, data... ) \
	_table_insert(tab, pos, data)

/*	void table_insert_n(
*	...	table(T) tab,
*	...	ptrdiff_t pos,
*	...	T * data_start,
*	...	size_t n
*	); */
# define table_insert_n( tab, pos, data_start, n ) \
	_table_insert_n(tab, pos, data_start, n)

/*	void table_push(
*	...	table(T) tab,
*	...	T data...
*	); */
# define table_push( tab, data... ) \
	_table_push(tab, data)

/*	void table_push_n(
*	...	table(T) tab,
*	...	const T * data_start,
*	...	size_t n
*	); */
# define table_push_n( tab, data_start, n ) \
	_table_push_n(tab, data_start, n)

/*	void table_remove(
*	...	table(T) tab,
*	... ptrdiff_t pos,
*	...	size_t n
*	); */
# define table_remove( tab, pos, n ) \
	_table_remove(tab, pos, n)

/*	void table_pop(
*	...	table(T) tab,
*	... size_t n
*	); */
# define table_pop( tab, n ) \
	_table_pop(tab, n)



/*	void table_reserve(
*	...	table(T) tab,
*	... size_t n
*	); */
# define table_reserve( tab, n ) \
	_table_reserve(tab, n)

/*	void table_shrink(
*	...	table(T) tab
*	);*/
# define table_shrink( tab ) \
	_table_shrink( tab )

/*	void table_resize(
*	...	table(T) tab,
*	... size_t n
*	); */
# define table_resize( tab, n ) \
	_table_resize(tab, n)



/*	void table_apply(
*	...	table(T) tab,
*	... void apply_expr( T * )
*	...	( example: `(x) ({*x += 1;})` )
*	); */
# define table_apply( tab, apply_expr ) \
	_table_apply(tab, apply_expr)

/*	void table_iter(
*	... const table(T) tab,
*	...	void iter_expr( const T * )
*	...	( example: `(x) ({printf("%d\n", *x);})` )
*	); */
# define table_iter( tab, iter_expr ) \
	_table_iter(tab, iter_expr)

/*	void table_filter(
*	...	table(T) tab,
*	...	bool cnd_expr( const T * )
*	...	( example: `(x) ({return x <= 42;})` )
*	);*/
# define table_filter( tab, cnd_expr ) \
	_table_filter(tab, cnd_expr)

/*	void table_sort(
*	...	table(T) tab,
*	... int cmp_expr( const T *, const T * )
*	...	( example: `(a, b) ({return a < b ? -1 : a != b;})` )
*	); */
# define table_sort( tab, cmp_expr ) \
	_table_sort(tab, cmp_expr)

/*	void table_slice(
*	...	table(T) tab,
*	... ptrdiff_t pos,
*	...	size_t n
*	); */
# define table_slice( tab, pos, n ) \
	_table_slice(tab, pos, n)

/*	T table_reduce(
*	...	const table(T) tab
*	); */
# define table_reduce( tab, reduce_expr ) \
	_table_reduce(tab, reduce_expr)



/*	int table_setbreak( void ); */
# define table_setbreak( ) \
	_table_setbreak()

/*	void table_break( int errnum ); */
# define table_break( errnum ) \
	_table_break(errnum)

#endif
