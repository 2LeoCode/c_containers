/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rslice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:10:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_rslice(
	list * lst,
	const listnode * start,
	size_t size
) {
	if (!start || !size) {
		list_clear(lst);
		return ;
	}
	listnode * iter = (void *)lst->tail;

	while (iter && iter != start) {
		listnode * tmp = iter->prev;

		free(iter->data);
		free(iter);
		iter = tmp;
	}
	*(void **)&lst->tail = iter;
	if (!iter) {
		*(void **)&lst->head = NULL;
		return ;
	}
	iter->next = NULL;
	*(size_t *)&lst->size = 0;
	while (iter && size - lst->size) {
		++*(size_t *)&lst->size;
		iter = iter->prev;
	}
	if (!iter)
		return ;
	iter->next->prev = NULL;
	*(void **)&lst->head = iter->next;
	while (iter) {
		listnode * tmp = iter->prev;

		free(iter->data);
		free(iter);
		iter = tmp;
	}
}
