/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:27:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/25 13:51:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

#include <stdlib.h>

static void trie_clear_r( t_trienode **node_addr, t_freef *free_fun ) {
	if (!*node_addr)
		return ;
	for (size_t i = 0; i <= UCHAR_MAX; ++i)
		trie_clear_r(&(*node_addr)->children[i], free_fun);
	if ((*node_addr)->data)
		free_fun((*node_addr)->data);
	free(*node_addr);
	*node_addr = NULL;
}

void trie_clear( t_trie *tri, t_freef *free_fun ) {
	for (size_t i = 0; i <= UCHAR_MAX; ++i)
		trie_clear_r((t_trienode**)&tri->root.children[i], free_fun);
}
