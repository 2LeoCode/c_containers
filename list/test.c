/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:06:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 11:56:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void destroy_list( list ** lst ) {
	list_clear(*lst);
	free(*lst);
	*lst = NULL;
}

list * args_to_list( int ac, char ** av ) {
	list * ptr = malloc(sizeof(list));

	if (!ptr)
		list_throw(LIST_ENOMEM);
	while (ac--)
		list_push_front(ptr, av[ac], strlen(av[ac]) + 1);
	return ptr;
}

int main( int argc, char ** argv ) {
	smart_list (a);
	list * b __attribute__((cleanup(destroy_list))) = NULL;
	int limit = 50;

	if (list_status() != LIST_OK) {
		puts("error");
		return -1;
	}

	b = args_to_list(argc - 1, argv + 1);
	list_apply(b, (elem), { printf("%s\n", (char*)elem); });
	srandom(time(NULL));
	for (int i = 0; i < 30; ++i)
		list_push_back_r(&a, random() % 100);
	puts("before:");
	list_apply(&a, (elem), { printf("%d\n", *(int*)elem); });
	puts("\nafter");
	list_filter(&a, (elem), { return *(int*)elem >= limit; });
	list_sort(&a, (a, b), { return (
		*(int*)a < *(int*)b ? -1 : *(int*)a != *(int*)b
	); });
	list_apply(&a, (elem), { printf("%d\n", *(int*)elem); });
	return 0;
}
