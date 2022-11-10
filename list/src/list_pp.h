/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:10:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 11:44:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_PP_H
# define LIST_PP_H

# define ARG_EMPTY( ... ) sizeof((char[]){ #__VA_ARGS__ } while (0) == 1

# define _smart_list( name ) \
	list __attribute__((cleanup(list_clear))) name = list_new()

# define _list_status( ) \
	setjmp(list_errbuf)

# define _list_throw( errnum ) \
	longjmp(list_errbuf, errnum)

# define _list_insert_r( lst, pos, data ) \
	list_insert(lst, pos, (typeof(data)[]){ data }, sizeof(data))

# define _list_push_front_r( lst, data ) \
	list_push_front(lst, (typeof(data)[]){ data }, sizeof(data))

# define _list_push_back_r( lst, data ) \
	list_push_back(lst, (typeof(data)[]){ data }, sizeof(data))

# define _list_apply( lst, appfn_args, appfn_body ) \
	do {\
		__attribute__((noinline)) void list_anonymous LIST_APPLY_ARGS appfn_args appfn_body\
		list_apply(lst, list_anonymous);\
	} while (0)

# define _list_map( dst, src, mapfn_args, mapfn_body ) \
	do {\
		__attribute__((noinline)) void * list_anonymous LIST_MAP_ARGS mapfn_args mapfn_body\
		list_map(dst, src, list_anonymous);\
	} while (0)

# define _list_filter( lst, cndfn_args, cndfn_body ) \
	do {\
		__attribute__((noinline)) bool list_anonymous LIST_CONDITION_ARGS cndfn_args cndfn_body\
		list_filter(lst, list_anonymous);\
	} while (0)

# define _list_filtermap( dst, src, cndfn_args, cndfn_body, mapfn_args, mapfn_body ) \
	do {\
		__attribute__((noinline)) bool list_anonymous LIST_CONDITION_ARGS cndfn_args cndfn_body\
		__attribute__((noinline)) void * list_anonymous1 LIST_MAP_ARGS mapfn_args mapfn_body\
		list_filtermap(dst, src, list_anonymous, list_anonymous1);\
	} while (0)

# define _list_slicemap( dst, src, start, size, mapfn_args, mapfn_body ) \
	do {\
		__attribute__((noinline)) void * list_anonymous LIST_MAP_ARGS mapfn_args mapfn_body\
		list_slicemap(dst, src, start, size, list_anonymous);\
	} while (0)

# define _list_rslicemap( dst, src, start, size, mapfn_args, mapfn_body ) \
	do {\
		__attribute__((noinline)) void * list_anonymous LIST_MAP_ARGS mapfn_args mapfn_body\
		list_rslicemap(dst, src, start, size, list_anonymous);\
	} while (0)

# define _list_find( lst, cndfn_args, cndfn_body ) \
	({\
		__attribute__((noinline)) bool list_anonymous LIST_CONDITION_ARGS cndfn_args cndfn_body\
		list_find(lst, list_anonymous);\
	})

# define _list_rfind( lst, cndfn_args, cndfn_body ) \
	({\
		__attribute__((noinline)) bool list_anonymous LIST_CONDITION_ARGS cndfn_args cndfn_body\
		list_rfind(lst, list_anonymous);\
	})

# define _list_reversemap( dst, src, mapfn_args, mapfn_body ) \
	do {\
		__attribute__((noinline)) void * list_anonymous LIST_MAP_ARGS mapfn_args mapfn_body\
		list_reversemap(dst, src, list_anonymous);\
	} while (0)

# define _list_sort( lst, cmpfn_args, cmpfn_body ) \
	do {\
		__attribute__((noinline)) int list_anonymous LIST_COMPARE_ARGS cmpfn_args cmpfn_body\
		list_sort(lst, list_anonymous);\
	} while (0)


# define _list_sortmap( dst, src, cmpfn_args, cmpfn_body, mapfn_args, mapfn_body ) \
	do {\
		__attribute__((noinline)) int list_anonymous LIST_COMPARE_ARGS cmpfn_args cmpfn_body\
		__attribute__((noinline)) void * list_anonymous2 LIST_MAP_ARGS mapfn_args mapfn_body\
		list_sortmap(dst, src, list_anonymous, list_anonymous2);\
	} while (0)

# define _list_reduce( lst, redfn_args, redfn_body ) \
	do {\
		__attribute__((noinline)) void * list_anonymous LIST_REDUCE_ARGS redfn_args redfn_body\
		list_reduce(lst, list_anonymous);\
	} while (0)

#endif
