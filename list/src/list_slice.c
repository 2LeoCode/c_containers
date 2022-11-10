/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:00:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_slice(
	list * lst,
	const listnode * start,
	size_t size
) {
	if (!start || !size) {
		list_clear(lst);
		return ;
	}
	listnode * iter = (void *)lst->head;

	while (iter && iter != start) {
		listnode * tmp = iter->next;

		free(iter->data);
		free(iter);
		iter = tmp;
	}
	*(void **)&lst->head = iter;
	if (!iter) {
		*(void **)&lst->tail = NULL;
		return ;
	}
	iter->prev = NULL;
	*(size_t *)&lst->size = 0;
	while (iter && size - lst->size) {
		++*(size_t *)&lst->size;
		iter = iter->next;
	}
	if (!iter)
		return ;
	iter->prev->next = NULL;
	*(void **)&lst->tail = iter->prev;
	while (iter) {
		listnode * tmp = iter->next;

		free(iter->data);
		free(iter);
		iter = tmp;
	}
}
