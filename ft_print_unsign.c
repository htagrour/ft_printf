/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:55:42 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 23:21:24 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_p(const char *format, va_list list, t_flags flags, int len)
{
	flags.nbr = va_arg(list, unsigned long long);
	flags.base = "0123456789abcdef";
	flags.p = 1;
	flags.nbase = 16;
	flags.key = 0;
	if (flags.point_f)
	{
		flags.with_f = flags.p_with;
		flags.sign_p = (flags.nbr) ? 0 : 1;
	}
	len = print_all(flags, len);
	return (case_hundler(format, list, len));
}

int		ft_print_o(const char *format, va_list list, t_flags flags, int len)
{
	flags.nbr = va_arg(list, unsigned int);
	flags.base = "01234567";
	flags.p = 0;
	flags.key = 0;
	flags.nbase = 8;
	len = print_all(flags, len);
	return (case_hundler(format, list, len));
}

int		ft_print_u(const char *format, va_list list, t_flags flags, int len)
{
	flags.nbr = va_arg(list, unsigned int);
	flags.base = "0123456789";
	flags.p = 0;
	flags.key = 0;
	flags.nbase = 10;
	len = print_all(flags, len);
	return (case_hundler(format, list, len));
}

int		ft_print_x_x(const char *format, va_list list, t_flags flags, int len)
{
	flags.nbr = va_arg(list, unsigned int);
	flags.base = "0123456789ABCDEF";
	flags.p = 0;
	flags.key = 0;
	flags.nbase = 16;
	len = print_all(flags, len);
	return (case_hundler(format, list, len));
}

int		ft_print_x(const char *format, va_list list, t_flags flags, int len)
{
	flags.nbr = va_arg(list, unsigned int);
	flags.base = "0123456789abcdef";
	flags.p = 0;
	flags.key = 0;
	flags.nbase = 16;
	len = print_all(flags, len);
	return (case_hundler(format, list, len));
}
