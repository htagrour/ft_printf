/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:53:17 by htagrour          #+#    #+#             */
/*   Updated: 2019/12/06 12:19:54 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define ULLONG	unsigned long long
# define ABS(n) ((n < 0) ? -n : n)

int				ft_printf(const char *format, ...);
typedef struct	s_flags
{
	int			point_f;
	int			with_f;
	int			zero_f;
	int			star_f;
	int			minus_f;
	int			key;
	int			p;
	char		*base;
	int			nbase;
	ULLONG		nbr;
	int			sign_p;
	int			p_with;
	int			char_;
}				t_flags;
typedef int		(*t_print_func)(const char *fmt,
		va_list list, t_flags flags, int len);
int				ft_printf(const char *format, ...);
int				case_hundler(const char *format, va_list list, int len);
int				ft_print_c(const char *format, va_list list,
							t_flags flags, int len);
int				ft_num_cases(ULLONG nbr, unsigned int base,
							const char *base_char);
int				ft_print_d(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_o(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_u(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_x(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_x_x(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_s(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_p(const char *format, va_list list,
							t_flags flags, int len);
int				ft_print_perc(const char *format, va_list list,
							t_flags flags, int len);
int				ft_putstr_(char *str, int width, int trigger);
int				ft_atoi(char **str);
int				ft_putchar_fd(char c, int fd);
int				ft_print_b_0(int nb, char c, int trigger);
int				ft_isdigit_spect(char c);
int				isthere_flags(t_flags flags);
int				ft_nb_digit(long long n, int base);
int				ft_strlen(char *str);
int				ft_print_all(t_flags flags, int len);
void			ft_swap(int *with_f, int *p_with, int var);
int				print_all(t_flags flags, int len);
#endif
