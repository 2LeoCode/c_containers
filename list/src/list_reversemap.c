/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reversemap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:10:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 23:24:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_reversemap)(
	list * dst,
	const list * src,
	list_map_fn * map
) {
	list_clear(dst);
	for (
		const listnode * iter = src->head;
		iter;
		iter = iter->next
	) {
		void * tmp = map(iter->data);
		if (!tmp)
			list_throw(LIST_ENOMEM);
		list_place(dst, dst->head, tmp);
	}
}
