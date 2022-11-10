/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_decorators.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:07:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/11/07 10:29:26 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATTRIBUTE_DECORATORS_H
# define ATTRIBUTE_DECORATORS_H

# define $ATTRIBUTE(attr) \
	__attribute__((attr))

# define $NORETURN \
	$ATTRIBUTE(noreturn)

# define $RETURNS_TWICE \
	$ATTRIBUTE(returns_twice)

# define $CONST \
	$ATTRIBUTE(const)

# define $PURE \
	$ATTRIBUTE(pure)

# define $MALLOC \
	$ATTRIBUTE(malloc)

# define $DEPRECATED \
	$ATTRIBUTE(deprecated)

# define $UNUSED \
	$ATTRIBUTE(unused)

# define $USED \
	$ATTRIBUTE(used)

# define $ALIGNED(n) \
	$ATTRIBUTE(aligned(n))

# define $PACKED \
	$ATTRIBUTE(packed)

# define $SECTION(name) \
	$ATTRIBUTE(section(name))

# define $WEAK \
	$ATTRIBUTE(weak)

# define $WEAK_ALIAS(name) \
	$ATTRIBUTE(weak, alias(name))

# define $ALIAS(name) \
	$ATTRIBUTE(alias(name))

# define $VISIBILITY_DEFAULT \
	$ATTRIBUTE(visibility("default"))

# define $VISIBILITY_HIDDEN \
	$ATTRIBUTE(visibility("hidden"))

# define $VISIBILITY_INTERNAL \
	$ATTRIBUTE(visibility("internal"))

# define $VISIBILITY_PROTECTED \
	$ATTRIBUTE(visibility("protected"))

# define $NOINLINE \
	$ATTRIBUTE(noinline)

# define $CONSTRUCTOR \
	$ATTRIBUTE(constructor)

# define $DESTRUCTOR \
	$ATTRIBUTE(destructor)

# define $FORMAT(type, fmt, args) \
	$ATTRIBUTE(format(type, fmt, args))

# define $FORMAT_ARG(fmt) \
	$ATTRIBUTE(format_arg(fmt))

# define $NON_NULL(...) \
	$ATTRIBUTE(nonnull(__VA_ARGS__))

# define $WARN_UNUSED_RESULT \
	$ATTRIBUTE(warn_unused_result)

# define $NO_INSTRUMENT_FUNCTION \
	$ATTRIBUTE(no_instrument_function)

# define $NO_SANITIZE_ADDRESS \
	$ATTRIBUTE(no_sanitize_address)

# define $NO_SANITIZE_THREAD \
	$ATTRIBUTE(no_sanitize_thread)

# define $NO_SANITIZE_MEMORY \
	$ATTRIBUTE(no_sanitize_memory)

# define $NO_SANITIZE_UNDEFINED \
	$ATTRIBUTE(no_sanitize_undefined)

# define $NO_SANITIZE_ALL \
	$ATTRIBUTE(no_sanitize_all)

# define $NO_SANITIZE(...) \
	$ATTRIBUTE(no_sanitize(__VA_ARGS__))

# define $CLEANUP(cleanup_function) \
	$ATTRIBUTE(cleanup(cleanup_function))

# define $INLINE \
	$ATTRIBUTE(always_inline)

# define $NOCLONE \
	$ATTRIBUTE(noclone)

# define $NOOPT \
	$ATTRIBUTE(optnone)

# define $NOOPTIMIZE \
	$ATTRIBUTE(optnone)

# define $SMART( type ) \
	$CLEANUP(type ## _destroy)

#endif
