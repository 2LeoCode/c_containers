/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:31:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 19:57:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

static void ptr_swap( uintptr_t * a, uintptr_t * b ) {
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void list_reverse( list * lst ) {
	for (
		listnode * iter = (void *)lst->head;
		iter;
		iter = iter->prev
	)
		ptr_swap((void *)&iter->prev, (void *)&iter->next);
	ptr_swap((void *)&lst->head, (void *)&lst->tail);
}
