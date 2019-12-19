/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:53:47 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 21:08:12 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	int			printf_return;
	va_list		list;

	va_start(list, format);
	printf_return = case_hundler(format, list, 0);
	va_end(list);
	if (printf_return < 0)
		return (-1);
	return (printf_return);
}
