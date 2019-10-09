/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:54:04 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 17:03:07 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int		ft_get_width(const char *str, int *p, va_list ap, t_params *param)
{
	int res;
	int i;
	int temp;

	i = *p;
	res = 0;
	if (str[i] == '*')
	{
		*p = i;
		if ((temp = va_arg(ap, int)) < 0)
		{
			param->minus = 1;
			return (0 - temp);
		}
		return (temp);
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	*p = i - 1;
	return (res);
}

int		ft_get_precision(const char *str, int *p, va_list ap)
{
	int i;
	int res;
	int temp;

	res = 0;
	i = *p;
	i++;
	if (str[i] == '*')
	{
		*p = i;
		if ((temp = va_arg(ap, int)) < 0)
			return (-1);
		return (temp);
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	*p = i - 1;
	return (res);
}

void	ft_sub_printf(va_list ap, int *p, int *res, const char *str)
{
	int			i;
	int			start;
	t_params	*param;

	param = 0;
	i = *p;
	start = i;
	param = ft_param_init(param);
	ft_readparams(param, &i, str, ap);
	ft_get_output_str(param, ap);
	*res += param->res;
	*res -= i - start + 1;
	*p = i;
	free(param);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, str);
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
			ft_sub_printf(ap, &i, &res, str);
		i++;
	}
	va_end(ap);
	return (res + i);
}
