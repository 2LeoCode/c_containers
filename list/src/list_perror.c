/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_perror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:33:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/11 11:17:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void list_perror( int errnum ) {
	const char *str = list_strerror(errnum);
	const size_t len = strlen(str);
	char buf[len + 1];
	memcpy(buf, str, len);
	buf[len] = '\n';
	if (write(2, buf, len + 1)) { }
}
