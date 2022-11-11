/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:17:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 09:27:42 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "src/array.h"

# include <stdlib.h>
# include <time.h>
# include <stdio.h>

# define debug_array(arr) \
	printf("size: %zu\ncapacity: %zu\n", (arr)->size, (arr)->capacity);\
	array_iter(arr, (x), ({ printf("%d\n", x); }))

int main( void ) {
	array_new(int, arr);

	if (array_status() != ARRAY_OK)
		return -1;

	srandom(time(NULL));
	for (int i = 0; i < 10; ++i)
		array_push(arr, i);
	array_slice(arr, 9, 1);
	debug_array(arr);
	return 0;
}
