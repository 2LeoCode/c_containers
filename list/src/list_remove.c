/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:54:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_remove(
	list * lst,
	const listnode * pos
) {
	if (!pos || !lst->head)
		return ;
	if (pos->prev)
		((listnode *)pos->prev)->next = (void *)pos->next;
	else
		*(void **)&lst->head = (void *)pos->next;
	if (pos->next)
		((listnode *)pos->next)->prev = (void *)pos->prev;
	else
		*(void **)&lst->tail = (void *)pos->prev;
	free((void *)pos->data);
	free((void *)pos);
	--*(size_t *)&lst->size;
}
