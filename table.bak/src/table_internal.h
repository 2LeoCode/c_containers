/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:27:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 13:54:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_INTERNAL_H
# define TABLE_INTERNAL_H

# include <stdint.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <setjmp.h>

# include "../table.h"

typedef struct s_table table;

struct s_table {
	size_t size,
		capacity,
		elemsize;
	int (* cpy_fun)();
	void (* clr_fun)();
	uint8_t data[];
};

extern int TABLE_STATUS;

#endif
