/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_trash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:12:32 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 17:03:30 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int	find_nb(long double nb, int n)
{
	long double	temp;
	int			i;
	int			res;

	i = 0;
	temp = ft_pow(10, ft_count_float_digit(nb));
	while (i < n + 1)
	{
		res = (nb / temp);
		nb -= temp * res;
		temp /= 10L;
		if (temp < 1.0L)
			i++;
	}
	return (res);
}

int	ft_print_params(t_params *param)
{
	ft_putstr("\n type:");
	ft_putendl(param->type);
	ft_putnbr(param->size);
	ft_putstr("\n");
	ft_putstr("width");
	ft_putnbr(param->width);
	ft_putstr("\n");
	ft_putstr("precision");
	ft_putnbr(param->precision);
	ft_putstr("\n");
	ft_putnbr(param->plus);
	ft_putstr("\n");
	ft_putnbr(param->minus);
	ft_putstr("\n");
	ft_putnbr(param->space);
	ft_putstr("\n");
	ft_putnbr(param->zero);
	ft_putstr("\n");
	ft_putnbr(param->hash);
	ft_putstr("\n");
	return (1);
}
