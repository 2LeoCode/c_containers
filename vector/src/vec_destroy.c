/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:35:06 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 21:46:03 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_int.h"

void (vec_destroy)( void * self )
{
	t_vec_int * self_int = get_vec_int(self);

	(vec_clear)(self);
	free(self_int);
}
