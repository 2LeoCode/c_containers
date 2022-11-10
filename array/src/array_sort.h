/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:54:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/10/06 08:58:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_SORT_H
# define ARRAY_SORT_H

# define _array_msort( front, front_size, back, back_size, cmp_args, cmp_body ) \
	do {\
		typeof(*(front)) * array_result = array_malloc(\
			sizeof(*(front)) * (front_size + back_size)\
		);\
		if (!array_result)\
			array_throw(ARRAY_ENOMEM);\
\
		size_t array_front_index = 0;\
		size_t array_back_index = 0;\
\
		while (\
			array_front_index < (front_size)\
			&& array_back_index < (back_size)\
		) {\
			typeof(*(front)) ARRAY_EXPAND_1 cmp_args = (front)[array_front_index];\
			typeof(*(back)) ARRAY_EXPAND_2 cmp_args = (back)[array_back_index];\
			int array_cmp_ret = (ARRAY_EXPAND_N cmp_body);\
\
			if (array_cmp_ret == -1) {\
				array_result[array_front_index + array_back_index] = (front)[array_front_index];\
				++array_front_index;\
			} else {\
				array_result[array_front_index + array_back_index] = (back)[array_back_index];\
				++array_back_index;\
			}\
		}\
		array_memcpy(\
			array_result + array_front_index + array_back_index,\
			front + array_front_index,\
			(front_size - array_front_index) * sizeof(*(front))\
		);\
		array_memcpy(\
			array_result + front_size + array_back_index,\
			back + array_back_index,\
			(back_size - array_back_index) * sizeof(*(back))\
		);\
		array_memcpy(\
			front, array_result,\
			(front_size + back_size) * sizeof(*(front))\
		);\
		free(array_result);\
	} while (0)

# define _array_sort( arr, cmp_args, cmp_body ) \
	do {\
		size_t array_group_cnt = (arr)->size;\
		size_t array_group_size = 1;\
\
		while (array_group_cnt > 1) {\
			for (\
				size_t i = 0;\
				i < array_group_cnt - 2;\
				i += 2\
			)\
				_array_msort(\
					(arr)->data + i * array_group_size, array_group_size,\
					(arr)->data + (i + 1) * array_group_size, array_group_size,\
					cmp_args, cmp_body\
				);\
			if (array_group_cnt % 2)\
				_array_msort(\
					(arr)->data + (array_group_cnt - 3) * array_group_size,\
					array_group_size * 2,\
					(arr)->data + (array_group_cnt - 1) * array_group_size,\
					(arr)->size - (array_group_cnt - 1) * array_group_size,\
					cmp_args, cmp_body\
				);\
			else\
				_array_msort(\
					(arr)->data + (array_group_cnt - 2) * array_group_size,\
					array_group_size,\
					(arr)->data + (array_group_cnt - 1) * array_group_size,\
					(arr)->size - (array_group_cnt - 1) * array_group_size,\
					cmp_args, cmp_body\
				);\
			array_group_cnt /= 2;\
			array_group_size *= 2;\
		}\
	} while (0)

#endif
