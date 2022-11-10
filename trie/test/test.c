/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:18:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/25 13:50:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../trie.h"

void trie_print_r( const t_trienode *cur_node, const unsigned char *prefix,
size_t prefix_len ) {
	if (!cur_node)
		return ;

	unsigned char next_prefix[prefix_len + 2];
	memcpy(next_prefix, prefix, prefix_len);
	next_prefix[prefix_len + 1] = 0;
	for (size_t i = 0; i <= UCHAR_MAX; ++i) {
		next_prefix[prefix_len] = i;
		trie_print_r(cur_node->children[i], next_prefix, prefix_len + 1);
	}
	if (cur_node->data)
		puts(prefix);
}

void trie_print( t_trie *tri ) {
	trie_print_r(&tri->root, "", 0);
}

int main( int argc, char *argv[] ) {
	t_trie trie = trie_new();

	for (int i = 1; i < argc; ++i)
		trie_insert(&trie, argv[i], strdup("kek"));
	trie_print(&trie);
	trie_remove(&trie, argv[1], free);
	printf("------\n");
	trie_print(&trie);
	return 0;
}
