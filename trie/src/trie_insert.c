/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:45:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/25 13:51:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

#include <stdlib.h>

static t_trienode *trienode_new( void ) {
	t_trienode *ptr = malloc(sizeof(*ptr));
	*ptr = (t_trienode){ };
	return ptr;
}

bool trie_insert( t_trie *tri, const unsigned char *key, void *data ) {
	if (!data)
		trie_error();
	if (!*key)
		return false;

	t_trienode *iter = (t_trienode*)&tri->root;
	while (*key) {
		if (!iter->children[*key]) {
			iter->children[*key] = trienode_new();
			if (!iter->children[*key])
				trie_error();
		}
		iter = iter->children[*key++];
	}

	if (iter->data)
		return false;
	iter->data = data;
	++*(size_t*)tri->size;
	return true;
}
