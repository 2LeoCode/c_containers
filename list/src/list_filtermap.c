/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filtermap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:55:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 23:22:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_filtermap)(
	list * dst,
	const list * src,
	list_condition_fn * condition,
	list_map_fn * map
) {
	list_clear(dst);
	for (
		const listnode * iter = src->head;
		iter;
		iter = iter->next
	) {
		if (!condition(iter->data))
			continue ;
		void * tmp = map(iter->data);
		if (!tmp)
			list_throw(LIST_ENOMEM);
		list_place(dst, NULL, tmp);
	}
}
