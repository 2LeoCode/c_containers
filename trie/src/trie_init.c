/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:52:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/24 19:52:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

#include <string.h>

void trie_init( t_trie *tri ) {
	memset(tri, 0, sizeof(*tri));
}
