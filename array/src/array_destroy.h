/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_destroy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:31:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/05 12:54:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_DESTROY_H
# define ARRAY_DESTROY_H

# define _array_destroy( arr ) \
	array_destroy((void *)&(arr))

void array_destroy( const void * arr );

#endif
