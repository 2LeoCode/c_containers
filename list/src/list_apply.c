/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:55:20 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 20:03:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_apply)(
	list * lst,
	list_apply_fn * apply
) {
	for (
		listnode * iter = (void *)lst->head;
		iter;
		iter = iter->next
	)
		apply(iter->data);
}
