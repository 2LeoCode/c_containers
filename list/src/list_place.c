/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:19:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_place( list * lst, const listnode * pos, void * data ) {
	listnode * new_node = malloc(sizeof(*new_node));

	if (!new_node) {
		free(data);
		list_throw(LIST_ENOMEM);
	}
	new_node->data = data;
	if (!lst->head) {
		new_node->prev = new_node->next = NULL;
		*(void **)&lst->head = *(void **)&lst->tail = new_node;
		return ;
	}
	new_node->next = (void *)pos;
	if (pos) {
		new_node->prev = (void *)pos->prev;
		if (pos == lst->head)
			*(void **)&lst->head = new_node;
		else
			((listnode *)pos->prev)->next = new_node;
		((listnode *)pos)->prev = new_node;
	} else {
		new_node->prev = (void *)lst->tail;
		((listnode *)lst->tail)->next = new_node;
		*(void **)&lst->tail = new_node;
	}
	++*(size_t *)&lst->size;
}
