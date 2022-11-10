/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:46:14 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 11:44:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H





# include <stddef.h>
# include <stdbool.h>
# include <setjmp.h>

# include "list_pp.h"





# define LIST_OK 0
# define LIST_ENOMEM 1





typedef struct s_list list;

typedef struct s_listnode listnode;

# define LIST_APPLY_ARGS( a ) ( void * a )
# define LIST_MAP_ARGS( a ) ( const void * a )
# define LIST_CONDITION_ARGS( a ) ( const void * a )
# define LIST_COMPARE_ARGS( a, b ) ( const void * a, const void * b )
# define LIST_REDUCE_ARGS( a, b ) ( const void * a, const void * b )

typedef void list_apply_fn LIST_APPLY_ARGS();
typedef void * list_map_fn LIST_MAP_ARGS();
typedef bool list_condition_fn LIST_CONDITION_ARGS();
typedef int list_compare_fn LIST_COMPARE_ARGS(,);
typedef void * list_reduce_fn LIST_REDUCE_ARGS(,);






struct s_list {
	const size_t size;
	const listnode * head;
	const listnode * tail;
};

struct s_listnode {
	void * data;
	listnode * next;
	listnode * prev;
};





extern jmp_buf list_errbuf;





# define list_status( ) \
	_list_status()



# define list_throw( errnum ) \
	_list_throw(errnum)



const char * list_strerror( int errnum );



void list_perror( int errnum );



list list_new( void );



void list_init( list * lst );



void list_clear( list * lst );



void list_insert(
	list * lst,
	const listnode * pos,
	void * data,
	size_t size
);
# define list_insert_r( lst, pos, data ) \
	_list_insert_r(lst, pos, data)



void list_push_front(
	list * lst,
	void * data,
	size_t size
);
# define list_push_front_r( lst, data ) \
	_list_push_front_r(lst, data)


void list_push_back(
	list * lst,
	void * data,
	size_t size
);
# define list_push_back_r( lst, data ) \
	_list_push_back_r(lst, data)


void list_remove(
	list * lst,
	const listnode * pos
);



void list_pop_front( list * lst );



void list_pop_back( list * lst );



void list_apply(
	list * lst,
	list_apply_fn * apply
);
# define list_apply( lst, appfn_args, appfn_body ) \
	_list_apply(lst, appfn_args, appfn_body)



void list_map(
	list * dst,
	const list * src,
	list_map_fn * map
);
# define list_map( dst, src, mapfn_args, mapfn_body ) \
	_list_map(dst, src, mapfn_args, mapfn_body)



void list_filter(
	list * lst,
	list_condition_fn * condition
);
# define list_filter( lst, cndfn_args, cndfn_body ) \
	_list_filter(lst, cndfn_args, cndfn_body)



void list_filtermap(
	list * dst,
	const list * src,
	list_condition_fn * condition,
	list_map_fn * map
);
# define list_filtermap( dst, src, cndfn_args, cndfn_body, mapfn_args, mapfn_body ) \
	_list_filtermap(dst, src, cndfn_args, cndfn_body, mapfn_args, mapfn_body)



void list_slice(
	list * lst,
	const listnode * start,
	size_t size
);



void list_rslice(
	list * lst,
	const listnode * start,
	size_t size
);



void list_slicemap(
	list * dst,
	const list * src,
	const listnode * start,
	size_t size,
	list_map_fn * map
);
# define list_slicemap( dst, src, start, size, mapfn_args, mapfn_body ) \
	_list_slicemap(dst, src, start, size, mapfn_args, mapfn_body)



void list_rslicemap(
	list * dst,
	const list * src,
	const listnode * start,
	size_t size,
	list_map_fn * map
);
# define list_rslicemap( dst, src, start, size, mapfn_args, mapfn_body ) \
	_list_rslicemap(dst, src, start, size, mapfn_args, mapfn_body)



const listnode * list_find(
	const list * lst,
	list_condition_fn * condition
);
# define list_find( lst, cndfn_args, cndfn_body ) \
	_list_find(lst, cndfn_args, cndfn_body)



const listnode * list_rfind(
	const list * lst,
	list_condition_fn * condition
);
# define list_rfind( lst, cndfn_args, cndfn_body ) \
	_list_rfind(lst, cndfn_args, cndfn_body)



void list_reverse( list * lst );



void list_reversemap(
	list * dst,
	const list * src,
	list_map_fn * map
);
# define list_reversemap( dst, src, mapfn_args, mapfn_body ) \
	_list_reversemap(dst, src, mapfn_args, mapfn_body)



void list_sort(
	list * lst,
	list_compare_fn * compare
);
# define list_sort( lst, cmpfn_args, cmpfn_body ) \
	_list_sort(lst, cmpfn_args, cmpfn_body)



void list_sortmap(
	list * dst,
	const list * src,
	list_compare_fn * compare,
	list_map_fn * map
);
# define list_sortmap( dst, src, cmpfn_args, cmpfn_body, mapfn_args, mapfn_body ) \
	_list_sortmap(dst, src, cmpfn_args, cmpfn_body, mapfn_args, mapfn_body)



void * list_reduce(
	const list * lst,
	list_reduce_fn * reduce
);
# define list_reduce( lst, redfn_args, redfn_body ) \
	_list_reduce(lst, redfn_args, redfn_body)

# define smart_list( name ) _smart_list(name)





#endif
