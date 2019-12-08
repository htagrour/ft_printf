/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:46:07 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 23:21:43 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_cases(ULLONG nbr, unsigned int base, const char *base_char)
{
	int	result;

	result = 1;
	if (nbr >= base)
	{
		result += ft_num_cases(nbr / base, base, base_char);
	}
	ft_putchar_fd(base_char[nbr % base], 1);
	return (result);
}
