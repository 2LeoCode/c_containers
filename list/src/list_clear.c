/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:42:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_clear( list * lst ) {
	listnode * iter = (void *)lst->head;

	while (iter) {
		listnode * tmp = iter->next;

		free(iter->data);
		free(iter);
		iter = tmp;
	}
	*(void **)&lst->head = *(void **)&lst->tail = NULL;
	*(size_t *)&lst->size = 0;
}
