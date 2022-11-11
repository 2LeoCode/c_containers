/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_find.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:58:57 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/11 23:16:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_FIND_H
# define VEC_FIND_H

# define vec_find_( self, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_find(self, _); \
	})

# define vec_find_from_( self, pos, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_find_from(self, pos, _); \
	})

# define vec_find_range_( self, pos, n, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_find_range(self, pos, n, _); \
	})

# define vec_rfind_( self, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_rfind(self, _); \
	})

# define vec_rfind_from_( self, pos, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_rfind_from(self, pos, _); \
	})

# define vec_rfind_range_( self, pos, n, func ) \
	({ \
		$NOINLINE \
		bool _ PP_PARAM1( const type *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		vec_rfind_range(self, pos, n, _); \
	})

ptrdiff_t vec_find( const void * self, bool (*func)() );
ptrdiff_t vec_find_from( const void * self, ptrdiff_t pos, bool (*func)() );
ptrdiff_t vec_find_range( const void * self, ptrdiff_t pos, size_t n, bool (*func)() );
ptrdiff_t vec_rfind( const void * self, bool (*func)() );
ptrdiff_t vec_rfind_from( const void * self, ptrdiff_t pos, bool (*func)() );
ptrdiff_t vec_rfind_range( const void * self, ptrdiff_t pos, size_t n, bool (*func)() );

#endif
