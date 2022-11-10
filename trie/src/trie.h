/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:20:59 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/25 13:47:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H

// *** INCLUDES ***

# include <setjmp.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

// ****************





// *** CONSTANTS ***

# define TRIE_OK 0
# define TRIE_ERR 1

// *****************





// *** TYPES ***

typedef void t_freef( void* );

typedef struct s_trie t_trie;
typedef struct s_trienode t_trienode;

struct s_trienode {
	void *data;
	t_trienode *children[UCHAR_MAX + 1];
};

struct s_trie {
	const size_t size;
	const t_trienode root;
};

// *************





// *** GLOBALS ***

extern jmp_buf g_trie_errbuf;

// ***************





// *** PROTOTYPES ***

# define trie_status() setjmp(g_trie_errbuf)
# define trie_error() longjmp(g_trie_errbuf, TRIE_ERR)

t_trie trie_new( void );
void trie_init( t_trie* );
bool trie_insert( t_trie*, const unsigned char*, void* );
bool trie_remove( t_trie*, const unsigned char*, t_freef* );
void *trie_find( t_trie*, const unsigned char* );
void trie_clear( t_trie*, t_freef* );

// ******************

#endif
