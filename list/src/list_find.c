/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:25:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 20:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

const listnode * (list_find)(
	const list * lst,
	list_condition_fn * condition
) {
	for (
		const listnode * iter = lst->head;
		iter;
		iter = iter->next
	) {
		if (condition(iter->data))
			return iter;
	}
	return NULL;
}
