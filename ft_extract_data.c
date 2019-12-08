/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:53:39 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/06 12:19:44 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_print_func g_functions[256] =
{
	['c'] = ft_print_c,
	['d'] = ft_print_d,
	['i'] = ft_print_d,
	['o'] = ft_print_o,
	['u'] = ft_print_u,
	['x'] = ft_print_x,
	['X'] = ft_print_x_x,
	['s'] = ft_print_s,
	['p'] = ft_print_p,
	['%'] = ft_print_perc
};

t_flags			init_flags(void)
{
	t_flags		flags;

	flags.zero_f = 0;
	flags.point_f = 0;
	flags.minus_f = 0;
	flags.with_f = 0;
	flags.p_with = 0;
	flags.sign_p = 0;
	return (flags);
}

char			flag_beleng(char c)
{
	char		*flags;

	flags = "dxXiupocs%";
	while (*flags)
	{
		if (c == *flags)
			return (c);
		flags++;
	}
	return (0);
}

static t_flags	extract_flags(char **format, va_list list)
{
	t_flags		flags;

	flags = init_flags();
	while (**format)
	{
		if (**format == '-')
			flags.minus_f = 1;
		if (**format == '0' && !flags.point_f)
			flags.zero_f = 1;
		if (**format == '.')
		{
			flags.point_f = 1;
			ft_swap(&flags.with_f, &flags.p_with, 0);
		}
		if (**format == '*')
			ft_swap(&flags.with_f, &flags.p_with, va_arg(list, int));
		if (ft_isdigit_spect(**format))
			ft_swap(&flags.with_f, &flags.p_with, ft_atoi(format));
		if (flag_beleng(**format))
			return (flags);
		(*format)++;
	}
	return (flags);
}

int				case_hundler(const char *format, va_list list, int len)
{
	int			c;
	t_flags		flags;

	while (*format)
	{
		c = (unsigned char)*format++;
		if (c != '%')
			len += ft_putchar_fd(c, 1);
		else
		{
			flags = extract_flags((char**)&format, list);
			c = (unsigned char)*format++;
			if (!g_functions[c])
			{
				if (!flag_beleng(c))
					break ;
				len += ft_putchar_fd(c, 1);
			}
			else
				return (g_functions[c](format, list, flags, len));
		}
	}
	return (len);
}
