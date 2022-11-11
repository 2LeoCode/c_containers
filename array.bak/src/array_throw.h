/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_throw.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:25:14 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/05 11:36:23 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_THROW_H
# define ARRAY_THROW_H

# define _array_throw( errnum ) \
	do {\
		array_errno = errnum;\
		longjmp(array_errbuf, errnum);\
	} while (0)

#endif
