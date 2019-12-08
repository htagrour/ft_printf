/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:42:48 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 22:49:32 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_b_0(int nb, char c, int trigger)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		if (trigger)
			ft_putchar_fd(c, 1);
		nb--;
		i++;
	}
	return (i);
}

int		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isdigit_spect(char c)
{
	return (c > '0' && c <= '9');
}

int		ft_atoi(char **str)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	while (**str)
	{
		if (ft_isdigit(**str))
			res = res * 10 + (**str - '0');
		else
			break ;
		(*str)++;
	}
	--(*str);
	return ((int)res);
}
