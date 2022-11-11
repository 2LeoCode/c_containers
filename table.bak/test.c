/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:22:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/21 16:02:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "table.h"

int main( void )
{
	smart_table(int) tb = NULL;
	const_smart_table(int) ctb = NULL;

	srandom(time(NULL));
	if (table_setbreak() != 0)
	{
		perror("table");
		return 1;
	}

	tb = table_new(int);
	ctb = table_new(int);
	table_push(ctb, 1);
	for (let i = 0; i < 20; ++i)
		table_push(tb, random() % 50 + 1, random() % 50 + 1,
			random() % 50 + 1, random() % 50 + 1);
	table_filter(tb, (x) ({ return *x <= 10; }));
	table_sort(tb, (a, b) ({ return *a < *b ? -1 : *a != *b; }));
	table_iter(tb, (x) ({ printf("%d\n", *x); }));
	printf("sum: %d\n",
		table_reduce(tb, (a, b) ({ return *a + *b; }))
	);
	return 0;
}
