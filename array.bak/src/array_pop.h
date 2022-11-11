/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:51:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/05 23:22:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_POP_H
# define ARRAY_POP_H

# define _array_pop( arr ) \
	array_remove(arr, arr->size - 1)

#endif
