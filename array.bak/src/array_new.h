/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:40:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/05 12:40:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_NEW_H
# define ARRAY_NEW_H

# define _array_new( type, name ) \
	array( type ) name __attribute__((cleanup(array_destroy)));\
	array_init(name)

#endif
