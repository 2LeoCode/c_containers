/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:53:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 12:09:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring_internal.h"

bool cstring_is_alpha( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isalpha(*begin))
			return false;
	return true;
}

bool cstring_is_alnum( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isalnum(*begin))
			return false;
	return true;
}

bool cstring_is_ascii( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isascii(*begin))
			return false;
	return true;
}

bool cstring_is_blank( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isblank(*begin))
			return false;
	return true;
}

bool cstring_is_cntrl( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!iscntrl(*begin))
			return false;
	return true;
}

bool cstring_is_digit( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isdigit(*begin))
			return false;
	return true;
}

bool cstring_is_graph( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isgraph(*begin))
			return false;
	return true;
}

bool cstring_is_lower( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!islower(*begin))
			return false;
	return true;
}

bool cstring_is_print( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isprint(*begin))
			return false;
	return true;
}

bool cstring_is_punct( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!ispunct(*begin))
			return false;
	return true;
}

bool cstring_is_space( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isspace(*begin))
			return false;
	return true;
}

bool cstring_is_upper( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isupper(*begin))
			return false;
	return true;
}

bool cstring_is_xdigit( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (!isxdigit(*begin))
			return false;
	return true;
}

bool cstring_is_title( const_cstring * self )
{
	const char * begin = *self;
	const char * end = *self + cstring_length(self);

	while (begin < end)
	{
		while (begin < end && !isalnum(*begin))
			++begin;
		if (*begin && !isdigit(*begin) && !isupper(*begin))
			return false;
		while (isalnum(*begin))
			++begin;
	}
	return true;
}

bool cstring_is_sentenced( const_cstring * self )
{
	const char * begin = *self;
	const char * end = *self + cstring_length(self);

	while (begin < end)
	{
		while (begin < end && !isalnum(*begin))
			++begin;
		if (*begin && !isupper(*begin))
			return false;
		while (*begin != '.')
		{
			if (*begin == 'i' && isspace(begin[1]) && (begin == *self || isspace(begin[-1])))
				return false;
			++begin;
		}
	}
	return true;
}

bool cstring_is_capitalized( const_cstring * self )
{
	const char * begin = *self - 1;
	const char * end = *self + cstring_length(self);

	while (++begin < end)
		if (isalpha(*begin) && !isupper(*begin))
			return false;
	return true;
}
