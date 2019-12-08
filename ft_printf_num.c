/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:52:28 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/05 22:42:35 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_p_case(t_flags flags)
{
	if (flags.p)
		return (ft_putstr_("0x", 2, 1));
	return (0);
}

int			ft_default_d(t_flags flags, int len, int trigger)
{
	flags.with_f = ABS(flags.with_f);
	if ((int)flags.nbr < 0 && flags.key)
		flags.with_f -= ft_nb_digit(flags.nbr, flags.nbase) + 1;
	else if (!flags.nbr)
		flags.with_f--;
	else if ((int)flags.nbr > 0 || !flags.key)
		flags.with_f -= ft_nb_digit(flags.nbr, flags.nbase);
	flags.with_f -= (flags.p) ? 2 : 0;
	flags.with_f += (flags.sign_p) ? 1 : 0;
	len += ft_print_b_0(flags.with_f, ' ', trigger);
	if ((int)flags.nbr < 0 && flags.key)
	{
		ft_putchar_fd('-', 1);
		flags.nbr = (-1 * flags.nbr);
		len++;
	}
	len += ft_p_case(flags);
	if (!flags.sign_p)
		len += ft_num_cases(flags.nbr, flags.nbase, flags.base);
	ft_print_b_0(flags.with_f, ' ', !trigger);
	return (len);
}

void		ft_flag_adjust(t_flags *flags)
{
	int		i;

	if (flags->zero_f && flags->p_with > 0 && flags->with_f < 0)
	{
		flags->with_f = ((int)flags->nbr < 0 && flags->key) ?
			flags->p_with - 1 : flags->p_with;
		flags->p_with = 0;
	}
	flags->p_with = ABS(flags->p_with);
	flags->with_f = (flags->with_f >= 0) ? flags->with_f : 1;
	if (flags->nbr)
	{
		i = ft_nb_digit(flags->nbr, flags->nbase);
		flags->with_f -= (flags->with_f > i) ? i : flags->with_f;
		if (flags->key)
			flags->p_with -= ((int)flags->nbr > 0) ?
				(flags->with_f + i) : (flags->with_f + 1 + i);
		else
			flags->p_with -= flags->with_f + i;
	}
	else
		flags->p_with -= (flags->with_f) ? flags->with_f : 0;
}

int			ft_point(t_flags flags, int len, int c, int trigger)
{
	flags.p_with = (c == '0' && flags.with_f < 0) ?
		ABS(flags.with_f) : flags.p_with;
	ft_flag_adjust(&flags);
	len += ft_print_b_0(flags.p_with, ' ', trigger);
	if ((int)(flags.nbr) < 0 && flags.key)
	{
		ft_putchar_fd('-', 1);
		flags.nbr = (unsigned)(-1 * flags.nbr);
		if (c == '0' || (flags.zero_f && flags.p_with > 0 && flags.with_f < 0))
			--flags.with_f;
		len++;
	}
	len += ft_print_b_0(flags.with_f, '0', 1);
	if (flags.nbr || (!flags.nbr && c == '0' && !flags.with_f))
		len += ft_num_cases(flags.nbr, flags.nbase, flags.base);
	ft_print_b_0(flags.p_with, ' ', !trigger);
	return (len);
}

int			print_all(t_flags flags, int len)
{
	flags.point_f = (flags.p) ? 0 : flags.point_f;
	if (!isthere_flags(flags) && flags.with_f >= 0)
		len = ft_default_d(flags, len, 1);
	if ((flags.minus_f || flags.with_f < 0) && !flags.zero_f && !flags.point_f)
		len = ft_default_d(flags, len, 0);
	if (flags.zero_f && !flags.point_f)
		len = ft_point(flags, len, '0', 0);
	if (flags.point_f && !flags.minus_f && flags.p_with >= 0)
		len = ft_point(flags, len, '.', 1);
	if (flags.point_f && (flags.minus_f || flags.p_with < 0))
		len = ft_point(flags, len, '-', 0);
	return (len);
}
