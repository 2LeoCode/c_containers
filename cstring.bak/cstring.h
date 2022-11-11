/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:06:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 13:59:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTRING_H
# define CSTRING_H

# include <stddef.h>
# include <stdint.h>
# include <setjmp.h>
# include <stdarg.h>
# include <stdbool.h>
# include "src/table/table.h"

# define CSTRING_NPOS PTRDIFF_MIN

typedef char * cstring;
typedef const char * const_cstring;

cstring cstring_new( void );
cstring cstring_new_with_capacity( size_t cap );

cstring cstring_from( const_cstring * other );
cstring cstring_from_raw( const char * other );
cstring cstring_from_raw_n( const char * other, size_t n );

void cstring_destroy( cstring * self );
void cstring_clear( cstring * self );

void cstring_assign( cstring * self, const_cstring * other );
void cstring_assign_raw( cstring * self, const char * other );
void cstring_assign_raw_n( cstring * self, const char * other, size_t n );

void cstring_append( cstring * self, const_cstring other );
void cstring_append_raw( cstring * self, const char * other );
void cstring_append_raw_n( cstring * self, const char * other, size_t n );

void cstring_insert( cstring * self, const_cstring other, ptrdiff_t pos );
void cstring_insert_raw( cstring * self, const char * other, ptrdiff_t pos );
void cstring_insert_raw_n( cstring * self, const char * other, size_t n, ptrdiff_t pos );

void cstring_erase( cstring * self, ptrdiff_t pos, size_t n );

void cstring_replace( cstring * self, const_cstring from, const_cstring to );
void cstring_replace_raw( cstring * self, const char * from, const char * to );
void cstring_replace_raw_n( cstring * self, const char * from, size_t n1, const char * to, size_t n2 );

void cstring_replace_first( cstring * self, const_cstring from, const_cstring to );
void cstring_replace_first_raw( cstring * self, const char * from, const char * to );
void cstring_replace_first_raw_n( cstring * self, const char * from, size_t n1, const char * to, size_t n2 );

void cstring_replace_last( cstring * self, const_cstring from, const_cstring to );
void cstring_replace_last_raw( cstring * self, const char * from, const char * to );
void cstring_replace_last_raw_n( cstring * self, const char * from, size_t n1, const char * to, size_t n2 );

void cstring_swap( cstring * self, cstring * other );

void cstring_reserve( cstring * self, size_t n );

void cstring_resize( cstring * self, size_t n );
void cstring_resize_fill( cstring * self, size_t n, char c );

void cstring_shrink( cstring * self );

void cstring_push( cstring * self, char c );
void cstring_pop( cstring * self );

void cstring_reverse( cstring * self );

void cstring_quote( cstring * self, char quote );
void cstring_unquote( cstring * self );

void cstring_trim( cstring * self, const_cstring chars );
void cstring_trim_raw( cstring * self, const char * chars );
void cstring_trim_raw_n( cstring * self, const char * chars, size_t n );

void cstring_trim_left( cstring * self, const_cstring chars );
void cstring_trim_left_raw( cstring * self, const char * chars );
void cstring_trim_left_raw_n( cstring * self, const char * chars, size_t n );

void cstring_trim_right( cstring * self, const_cstring chars );
void cstring_trim_right_raw( cstring * self, const char * chars );
void cstring_trim_right_raw_n( cstring * self, const char * chars, size_t n );

void cstring_to_upper( cstring * self );
void cstring_to_lower( cstring * self );
void cstring_title( cstring * self );
void cstring_sentence( cstring * self );
void cstring_capitalize( cstring * self );
void cstring_uncapitalize( cstring * self );

bool cstring_is_alpha( const_cstring * self );
bool cstring_is_digit( const_cstring * self );
bool cstring_is_alnum( const_cstring * self );
bool cstring_is_space( const_cstring * self );
bool cstring_is_print( const_cstring * self );
bool cstring_is_punct( const_cstring * self );
bool cstring_is_cntrl( const_cstring * self );
bool cstring_is_graph( const_cstring * self );
bool cstring_is_blank( const_cstring * self );
bool cstring_is_xdigit( const_cstring * self );
bool cstring_is_ascii( const_cstring * self );
bool cstring_is_upper( const_cstring * self );
bool cstring_is_lower( const_cstring * self );
bool cstring_is_title( const_cstring * self );
bool cstring_is_capitalized( const_cstring * self );
bool cstring_is_sentenced( const_cstring * self );

size_t cstring_length( const_cstring * self );
size_t cstring_capacity( const_cstring * self );

int cstring_compare( const_cstring * self, const_cstring * other );
int cstring_compare_raw( const_cstring * self, const char * other );
int cstring_compare_raw_n( const_cstring * self, const char * other, size_t n );

bool cstring_starts_with( const_cstring * self, const_cstring * other );
bool cstring_starts_with_raw( const_cstring * self, const char * other );
bool cstring_starts_with_raw_n( const_cstring * self, const char * other, size_t n );

bool cstring_ends_with( const_cstring * self, const_cstring * other );
bool cstring_ends_with_raw( const_cstring * self, const char * other );
bool cstring_ends_with_raw_n( const_cstring * self, const char * other, size_t n );

bool cstring_contains( const_cstring * self, const_cstring * other );
bool cstring_contains_raw( const_cstring * self, const char * other );
bool cstring_contains_raw_n( const_cstring * self, const char * other, size_t n );

ptrdiff_t cstring_find( const_cstring * self, const_cstring * other, ptrdiff_t pos );
ptrdiff_t cstring_find_raw( const_cstring * self, const char * other, ptrdiff_t pos );
ptrdiff_t cstring_find_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos );

ptrdiff_t cstring_rfind( const_cstring * self, const_cstring * sother, ptrdiff_t pos );
ptrdiff_t cstring_rfind_raw( const_cstring * self, const char * other, ptrdiff_t pos );
ptrdiff_t cstring_rfind_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos );

ptrdiff_t cstring_find_first_of( const_cstring * self, const_cstring * other, ptrdiff_t pos );
ptrdiff_t cstring_find_first_of_raw( const_cstring * self, const char * other, ptrdiff_t pos );
ptrdiff_t cstring_find_first_of_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos );

ptrdiff_t cstring_find_last_of( const_cstring * self, const_cstring * other, ptrdiff_t pos );
ptrdiff_t cstring_find_last_of_raw( const_cstring * self, const char * other, ptrdiff_t pos );
ptrdiff_t cstring_find_last_of_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos );

ptrdiff_t cstring_find_first_not_of( const_cstring * self, const_cstring * other, ptrdiff_t pos );
ptrdiff_t cstring_find_first_not_of_raw( const_cstring * self, const char * other, ptrdiff_t pos );
ptrdiff_t cstring_find_first_not_of_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos );

ptrdiff_t cstring_find_last_not_of( const_cstring * self, const_cstring * other, ptrdiff_t pos );
ptrdiff_t cstring_find_last_not_of_raw( const_cstring * self, const char * other, ptrdiff_t pos );
ptrdiff_t cstring_find_last_not_of_raw_n( const_cstring * self, const char * other, size_t n, ptrdiff_t pos );

table(cstring) cstring_split( const_cstring * self, const_cstring * delim );
table(cstring) cstring_split_raw( const_cstring * self, const char * delim );
table(cstring) cstring_split_raw_n( const_cstring * self, const char * delim, size_t n );

table(cstring) cstring_split_lines( const_cstring * self );

cstring cstring_substr( const_cstring * self, ptrdiff_t pos, size_t n );
cstring cstring_substr_to( const_cstring * self, ptrdiff_t pos );
cstring cstring_substr_from( const_cstring * self, ptrdiff_t pos );

cstring cstring_join( const_cstring * strings, size_t n, const_cstring * delim );
cstring cstring_join_raw( const_cstring * strings, size_t n, const char * delim );
cstring cstring_join_raw_n( const_cstring * strings, size_t n1, const char * delim, size_t n2 );

cstring cstring_join_lines( const_cstring * strings, size_t n );

cstring cstring_format( const char * fmt, ... );
cstring cstring_format_v( const char * fmt, va_list args );

int cstring_print( const_cstring * self );
int cstring_println( const_cstring * self );
int cstring_fprint( int fd, const_cstring * self );
int cstring_fprintln( int fd, const_cstring * self );

int cstring_break( void );
void cstring_throw( int errnum );

extern jmp_buf CSTRING_ERRBUF;

#endif
