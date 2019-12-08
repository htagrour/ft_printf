/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:44:03 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 23:20:51 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_d(const char *format, va_list list, t_flags flags, int len)
{
	flags.nbr = va_arg(list, int);
	flags.nbase = 10;
	flags.base = "0123456789";
	flags.p = 0;
	flags.key = 1;
	len = print_all(flags, len);
	return (case_hundler(format, list, len));
}
