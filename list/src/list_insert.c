/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:24:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_insert(
	list * lst,
	const listnode * pos,
	void * data,
	size_t size
) {
	void * data_copy = malloc(size);
	if (!data_copy)
		list_throw(LIST_ENOMEM);
	memcpy(data_copy, data, size);
	list_place(lst, pos, data_copy);
}
