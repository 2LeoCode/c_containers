/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:42:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 20:03:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_filter)(
	list * lst,
	list_condition_fn * condition
) {
	const listnode * iter = lst->head;

	while (iter) {
		const listnode * tmp = iter->next;

		if (!condition(iter->data))
			list_remove(lst, iter);
		iter = tmp;
	}
}
