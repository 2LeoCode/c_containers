/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:17:20 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 20:04:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void * (list_reduce)(
	const list * lst,
	list_reduce_fn * reduce
) {
	void * final = NULL;
	void * old;

	for (
		const listnode * iter = lst->head;
		iter;
		iter = iter->next
	) {
		old = final;
		final = reduce(final, iter->data);
		free(old);
		if (!final)
			list_throw(LIST_ENOMEM);
	}
	return final;
}
