/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:41:20 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 23:05:48 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_default_s(char *str, t_flags flags, int len, int trigger)
{
	flags.with_f = ABS(flags.with_f) - ft_strlen(str);
	len += ft_putstr_(str, ft_strlen(str), trigger);
	len += ft_print_b_0(flags.with_f, ' ', 1);
	ft_putstr_(str, ft_strlen(str), !trigger);
	return (len);
}

void	ft_extrahelp(char *str, int *width, int *p_width)
{
	if (*width < 0)
		*width = (!str) ? 6 : ft_strlen(str);
	*p_width = ABS(*p_width);
}

int		ft_point_s(char *str, t_flags flags, int len, int c)
{
	ft_extrahelp(str, &flags.with_f, &flags.p_with);
	flags.p_with -= ft_putstr_(str, flags.with_f, c);
	len += ft_print_b_0(flags.p_with, ' ', 1);
	len += ft_putstr_(str, flags.with_f, !c);
	return (len);
}

int		ft_print_s(const char *format, va_list list, t_flags flags, int len)
{
	char	*str;

	str = va_arg(list, char*);
	if (!isthere_flags(flags))
		len = ft_default_s(str, flags, len, 0);
	if (flags.minus_f && !flags.point_f)
		len = ft_default_s(str, flags, len, 1);
	if (flags.point_f && !flags.minus_f && flags.p_with >= 0)
		len = ft_point_s(str, flags, len, 0);
	if (flags.point_f && (flags.minus_f || flags.p_with < 0))
		len = ft_point_s(str, flags, len, 1);
	return (case_hundler(format, list, len));
}
