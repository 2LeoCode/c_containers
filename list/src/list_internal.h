/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:48:16 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/03 23:56:38 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_H
# define LIST_INTERNAL_H

# include "list.h"

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# undef list

void list_place(
	list * lst,
	const listnode * pos,
	void * data
);

#endif
