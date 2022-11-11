/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_push.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:47:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/05 12:17:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_PUSH_H
# define ARRAY_PUSH_H

# define _array_push(arr, value) \
	array_insert(arr, (arr)->size, value)

#endif
