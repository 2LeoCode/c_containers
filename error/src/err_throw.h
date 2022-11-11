/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_throw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:38:56 by lsuardi           #+#    #+#             */
/*   Updated: 2022/11/10 17:40:53 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_THROW_H
# define ERR_THROW_H

extern jmp_buf err_buf;
extern char * err_msg;

# define err_throw_( msg ) \
	do { \
		err_msg = msg; \
		longjmp(err_buf, 1); \
	} while (0)

#endif
