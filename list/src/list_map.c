/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:04:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 23:23:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_map)(
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
		list_place(dst, NULL, tmp);
	}
}
