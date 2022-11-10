/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:57:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/24 20:11:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

void *trie_find( t_trie *tri, const unsigned char *key ) {
	t_trienode *iter = (t_trienode*)&tri->root;

	while (*key) {
		if (!iter->children[*key])
			return NULL;
		iter = iter->children[*key++];
	}
	return iter->data;
}
