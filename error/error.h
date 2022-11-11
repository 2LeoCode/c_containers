/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:30:32 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 17:36:22 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <setjmp.h>
# include "src/err_catch.h"
# include "src/err_throw.h"

/*	int err_catch(
*	...	(const char *)({...})
*	); */
# define err_catch( func ) \
	err_catch_(func)

/*	void err_throw(
*	...	const char * msg
*	); */
# define err_throw( msg ) \
	err_throw_( msg )

#endif
