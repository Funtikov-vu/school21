/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:40:26 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/24 17:50:26 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

static int	ft_get_len_sgn(long long int *nb, t_params *param, char *sgn)
{
	int len;

	*sgn = 0;
	if (*nb < 0)
	{
		*nb = 0 - *nb;
		*sgn = '-';
	}
	else if (param->plus == 1)
		*sgn = '+';
	else if (param->space == 1)
		*sgn = ' ';
	if (!(*nb) && !param->precision)
		len = 0;
	else
		len = ft_get_itoa_len_uns(*nb, 10);
	return (len);
}

void		ft_printf_sgn(long long int nb, t_params *param)
{
	int		len;
	char	sgn;

	len = ft_get_len_sgn(&nb, param, &sgn);
	param->res = len + !!sgn;
	if (!param->minus && !param->zero && param->width > param->precision)
		ft_zs(param->width, ft_max(len, param->precision) + !!sgn,
				0, &(param->res));
	if (sgn)
		ft_putchar_fd(sgn, 1);
	if (param->zero)
		ft_zs(param->width, len + !!sgn, 1, &(param->res));
	else if (param->precision != -1)
		ft_zs(param->precision, len, 1, &(param->res));
	if (nb || param->precision)
		ft_putnbr_base(nb, 10, 0);
	if (param->minus)
		ft_zs(param->width, ft_max(len, param->precision) + !!sgn,
				0, &(param->res));
}

void		ft_read_dec(t_params *param, va_list ap)
{
	long long int nb;

	if (ft_strchr(param->type, 'D'))
		nb = va_arg(ap, long int);
	else if (!ft_strncmp(param->type, "ll", 2))
		nb = va_arg(ap, long long int);
	else if (!ft_strncmp(param->type, "l", 1))
		nb = va_arg(ap, long int);
	else if (!ft_strncmp(param->type, "hh", 2))
		nb = (char)va_arg(ap, int);
	else if (!ft_strncmp(param->type, "h", 1))
		nb = (short int)va_arg(ap, int);
	else if (!ft_strncmp(param->type, "j", 1))
		nb = va_arg(ap, intmax_t);
	else if (!ft_strncmp(param->type, "z", 1))
		nb = va_arg(ap, size_t);
	else
		nb = va_arg(ap, int);
	ft_printf_sgn(nb, param);
}
