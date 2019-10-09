/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:50:40 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 17:04:08 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

void	ft_printf_wstr(t_params *param, wchar_t *str)
{
	int len;

	if (!str)
	{
		ft_printf_str(param, 0);
		return ;
	}
	len = ft_strwlen(str);
	if (param->precision != -1 && param->precision < len)
		len = ft_strwlen_prec(str, param->precision);
	param->res = len;
	if (!param->minus)
		ft_zs(param->width, len, param->zero, &(param->res));
	ft_putnwstr_fd(str, len, 1);
	if (param->minus)
		ft_zs(param->width, len, 0, &(param->res));
}

void	ft_printf_str(t_params *param, char *str)
{
	int len;

	if (!str)
	{
		str = ft_strdup("(null)");
		ft_printf_str(param, str);
		free(str);
		return ;
	}
	len = ft_strlen(str);
	if (param->precision != -1 && param->precision < len)
		len = param->precision;
	param->res = len;
	if (!param->minus)
		ft_zs(param->width, len, param->zero, &(param->res));
	ft_putnstr_fd(str, len, 1);
	if (param->minus)
		ft_zs(param->width, len, 0, &(param->res));
}

void	ft_readwchar(t_params *param, wchar_t c)
{
	int len;

	len = ft_wcharlen(c);
	param->res = len;
	if (!param->minus)
		ft_zs(param->width, len, param->zero, &(param->res));
	ft_putwchar(c);
	if (param->minus)
		ft_zs(param->width, len, 0, &(param->res));
}

void	ft_readchar(t_params *param, va_list ap)
{
	int		len;

	if (ft_strnchr(param->type, "Cl"))
	{
		ft_readwchar(param, (wchar_t)va_arg(ap, wint_t));
		return ;
	}
	if (param->width == 0)
		param->width = 1;
	len = 1;
	param->res = 1;
	if (!param->minus)
		ft_zs(param->width, len, param->zero, &(param->res));
	ft_putchar((char)va_arg(ap, int));
	if (param->minus)
		ft_zs(param->width, len, 0, &(param->res));
}

void	ft_readmem(t_params *param, void *in)
{
	int len;

	if (!in && !param->precision)
		len = 0;
	else
		len = ft_get_itoa_len_uns((unsigned long long)in, 16);
	param->res = len + 2;
	if (!param->minus && !param->zero && param->width > param->precision)
		ft_zs(param->width, ft_max(len, param->precision) + 2,
			0, &(param->res));
	ft_putstr_fd("0x", 1);
	if (param->zero)
		ft_zs(param->width, len + 2, 1, &(param->res));
	else if (param->precision != -1)
		ft_zs(param->precision, len, 1, &(param->res));
	if (!in && param->precision)
		ft_putstr_fd("0", 1);
	else if (in)
		ft_putnbr_base((unsigned long long)in, 16, 0);
	if (param->minus)
		ft_zs(param->width, ft_max(len, param->precision) + 2,
				0, &(param->res));
}
