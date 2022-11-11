/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:00:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/10 13:56:58 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cstring.h"
# include <stdio.h>
# include <string.h>

int main( void )
{
	if (cstring_break() == 0)
	{
		printf("breakpoint reached\n");
		return (0);
	}
	printf("Hello world\n");
	cstring_throw(1);
	return (0);
}
