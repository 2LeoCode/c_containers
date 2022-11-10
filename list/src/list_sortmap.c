/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sortmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:35:14 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 23:57:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void (list_sortmap)(
	list * dst,
	const list * src,
	list_compare_fn * compare,
	list_map_fn * map
) {
	(list_map)(dst, src, map);
	(list_sort)(dst, compare);
}
