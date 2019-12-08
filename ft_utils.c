/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 02:55:43 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 21:36:37 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_digit(long long n, int base)
{
	if (!n)
		return (0);
	return (1 + ft_nb_digit(n / base, base));
}

int		isthere_flags(t_flags flags)
{
	return (flags.minus_f || flags.point_f || flags.zero_f);
}

int		ft_putstr_(char *str, int width, int trigger)
{
	int		i;
	char	*tem;

	i = 0;
	if (!str)
		tem = "(null)";
	else
		tem = str;
	while (tem[i] && width)
	{
		if (trigger)
			ft_putchar_fd(tem[i], 1);
		width--;
		i++;
	}
	return (i);
}

void	ft_swap(int *with_f, int *p_with, int var)
{
	if (*with_f)
	{
		*p_with = *with_f;
		*with_f = var;
	}
	else
		*with_f = var;
}

int		ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (6);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
