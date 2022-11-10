/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rslicemap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:23:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 23:26:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_rslicemap)(
	list * dst,
	const list * src,
	const listnode * start,
	size_t size,
	list_map_fn * map
) {
	list_clear(dst);
	const listnode * iter = src->tail;

	while (iter && iter != start)
		iter = iter->prev;
	while (iter && size - dst->size) {
		void * tmp = map(iter->data);
		if (!tmp)
			list_throw(LIST_ENOMEM);
		list_place(dst, dst->head, tmp);
		iter = iter->prev;
	}
}
