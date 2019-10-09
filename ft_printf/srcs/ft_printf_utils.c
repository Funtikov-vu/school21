/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:24:42 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 16:49:52 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int			ft_wstrisprintable(wchar_t *str)
{
	while (*str)
	{
		if (*str > 127)
			return (0);
		str++;
	}
	return (1);
}

void		ft_printchar(t_params *param)
{
	int	len;

	if (param->width == 0)
		param->width = 1;
	len = 1;
	param->res = 1;
	if (!param->minus)
		ft_zs(param->width, len, param->zero, &(param->res));
	ft_putchar_fd(param->type[0], 1);
	if (param->minus)
		ft_zs(param->width, len, 0, &(param->res));
}

long double	ft_pow(long double nb, int pow)
{
	long double res;

	if (pow == 0)
		return (1.0L);
	res = 1;
	if (pow > 0)
	{
		while (pow-- != 0)
			res *= nb;
	}
	else
	{
		while (pow++ != 0)
			res /= nb;
	}
	return (res);
}

int			ft_count_float_digit(long double nb)
{
	int			i;
	long double temp;

	i = 0;
	temp = 1.0;
	while (temp < nb)
	{
		i++;
		temp *= 10;
	}
	if (temp > nb && i > 0)
		return (i - 1);
	return (i);
}

t_params	*ft_param_init(t_params *param)
{
	if (!param)
		param = (t_params*)malloc(sizeof(t_params));
	ft_memset(param->type, '\0', 5);
	param->size = 0;
	param->width = 0;
	param->precision = -1;
	param->plus = 0;
	param->minus = 0;
	param->space = 0;
	param->zero = 0;
	param->hash = 0;
	param->res = 0;
	return (param);
}
