/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_break.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:33:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/12 19:15:00 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_BREAK_H
# define TABLE_BREAK_H

# include <setjmp.h>

# define _table_setbreak( ) \
	setjmp(TABLE_BREAKPOINT)

# define _table_break( errnum ) \
	do\
	{\
		errno = errnum;\
		longjmp(TABLE_BREAKPOINT, 1);\
	}\
	while (0)

extern jmp_buf TABLE_BREAKPOINT;

#endif
