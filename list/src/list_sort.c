/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:12:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 20:04:07 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

static void merge_push(
	listnode ** head,
	listnode ** tail,
	listnode ** cur
) {
	if (!*head)
		*head = *tail = *cur;
	else {
		(*tail)->next = *cur;
		(*cur)->prev = *tail;
		*tail = *cur;
	}
	*cur = (*cur)->next;
}

static void merge_split(
	listnode * source,
	listnode ** front,
	listnode ** back
) {
	listnode * slow = source;
	listnode * fast = source->next;

	while (fast) {
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = (*back)->prev = NULL;
}

static listnode * merge(
	listnode * front,
	listnode * back,
	list_compare_fn * compare
) {
	listnode * result = NULL;
	listnode * result_tail = NULL;

	while (front != NULL && back != NULL) {
		if (compare(front->data, back->data) < 0)
			merge_push(&result, &result_tail, &front);
		else
			merge_push(&result, &result_tail, &back);
	}
	while (front != NULL)
		merge_push(&result, &result_tail, &front);
	while (back != NULL)
		merge_push(&result, &result_tail, &back);
	return result;
}

static void merge_sort(
	listnode ** head,
	list_compare_fn * compare
) {
	listnode * a, * b;

	if (!*head || !(*head)->next)
		return ;
	merge_split(*head, &a, &b);
	merge_sort(&a, compare);
	merge_sort(&b, compare);
	*head = merge(a, b, compare);
}

void (list_sort)(
	list * lst,
	list_compare_fn * compare
) {
	merge_sort((void *)&lst->head, compare);
}
