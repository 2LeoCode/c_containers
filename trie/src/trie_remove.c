/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:01:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/25 13:48:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

#include <stdlib.h>

static bool trienode_has_children( t_trienode *node ) {
	for (size_t i = 0; i <= UCHAR_MAX; ++i)
		if (node->children[i])
			return true;
	return false;
}

static bool trie_remove_r( t_trienode **node, const unsigned char *id,
t_freef *free_fun ) {
	if (!*id) {
		if (!(*node)->data)
			return false;
		free_fun((*node)->data);
		(*node)->data = NULL;
		if (!trienode_has_children(*node)) {
			free(*node);
			*node = NULL;
		}
		return true;
	}

	if (!(*node)->children[*id]
	|| !trie_remove_r(&(*node)->children[*id], id + 1, free_fun))
		return false;

	if (!(*node)->data && !trienode_has_children(*node)) {
		free(*node);
		*node = NULL;
	}
	return true;
}

bool trie_remove( t_trie *tri, const unsigned char *key, t_freef *free_fun ) {
	if (!(trie_remove_r(
		(t_trienode**)&tri->root.children[*key],
		key + 1, free_fun
	)))
		return false;
	--*(size_t*)tri->size;
	return true;
}
