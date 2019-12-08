/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:53:29 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 23:25:06 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		default_c(int c, int len, t_flags flags, int trigger)
{
	flags.with_f = ABS(flags.with_f);
	len += ft_print_b_0(--flags.with_f, c, trigger);
	ft_putchar_fd(flags.char_, 1);
	len++;
	ft_print_b_0(flags.with_f, c, !trigger);
	return (len);
}

int		ft_print_char(t_flags flags, int len)
{
	if (flags.point_f)
		flags.with_f = flags.p_with;
	if (!isthere_flags(flags) && flags.with_f >= 0)
		len = default_c(' ', len, flags, 1);
	if ((flags.with_f < 0 || flags.minus_f) && !flags.point_f)
		len = default_c(' ', len, flags, 0);
	if (flags.point_f && flags.with_f >= 0 && !flags.minus_f && !flags.zero_f)
		len = default_c(' ', len, flags, 1);
	if (flags.point_f && !flags.minus_f && flags.with_f >= 0 && flags.zero_f)
		len = default_c('0', len, flags, 1);
	if (flags.point_f && (flags.with_f < 0 || flags.minus_f))
		len = default_c(' ', len, flags, 0);
	return (len);
}

int		ft_print_c(const char *format, va_list list, t_flags flags, int len)
{
	flags.char_ = va_arg(list, int);
	len = ft_print_char(flags, len);
	return (case_hundler(format, list, len));
}

int		ft_print_perc(const char *format, va_list list, t_flags flags, int len)
{
	flags.char_ = '%';
	len = ft_print_char(flags, len);
	return (case_hundler(format, list, len));
}
