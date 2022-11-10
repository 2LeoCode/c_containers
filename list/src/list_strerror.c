/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_strerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:29:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/09/30 22:33:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

#define LIST_ERRCNT 1

const char * list_strerror( int errnum ) {
	static const char * err_str[] = {
		"An unknown error occured",
		"Out of memory"
	};

	return err_str[errnum * (errnum < 0 || errnum > LIST_ERRCNT)];
}
