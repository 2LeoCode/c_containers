/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_catch.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:17:57 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 17:41:09 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CATCH_H
# define ERR_CATCH_H

# include "common/pp_utilities.h"

extern jmp_buf err_buf;
extern char * err_msg;

# define err_catch_( func ) \
	do { \
		void _ PP_PARAM1(const char *, PP_EXPAND_PARAM func) \
		PP_EXPAND_BODY func \
		if (setjmp(err_buf) == 1) \
			_(err_msg); \
	} while (0)

#endif
