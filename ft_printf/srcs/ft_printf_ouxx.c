/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ouxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:30:06 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/24 16:53:13 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int		ft_base(char c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'u' || c == 'U')
		return (10);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'x')
		return (16);
	else if (c == 'X')
		return (-16);
	return (0);
}

void	ft_read_unsgn(t_params *param, va_list ap)
{
	unsigned long long	nb;
	int					base;

	if (ft_strnchr(param->type, "OU"))
		nb = va_arg(ap, unsigned long int);
	else if (!ft_strncmp(param->type, "ll", 2))
		nb = va_arg(ap, unsigned long long int);
	else if (!ft_strncmp(param->type, "l", 1))
		nb = va_arg(ap, unsigned long int);
	else if (!ft_strncmp(param->type, "hh", 2))
		nb = (unsigned char)va_arg(ap, unsigned int);
	else if (!ft_strncmp(param->type, "h", 1))
		nb = (unsigned short int)va_arg(ap, unsigned int);
	else if (!ft_strncmp(param->type, "j", 1))
		nb = va_arg(ap, unsigned long long int);
	else if (!ft_strncmp(param->type, "z", 1))
		nb = va_arg(ap, size_t);
	else
		nb = va_arg(ap, unsigned int);
	if ((base = ft_base(param->type[ft_strlen(param->type) - 1])) < 0)
		ft_printf_unsgn(nb, 16, param, 1);
	else
		ft_printf_unsgn(nb, base, param, 0);
}

int		ft_get_len_dif(long long int nb, int base, t_params *param)
{
	int len_dif;

	if (base == 16 && param->hash && nb)
		len_dif = 2;
	else if (base == 8 && param->hash && (param->precision != -1 || nb))
		len_dif = 1;
	else
		len_dif = 0;
	return (len_dif);
}

void	ft_printf_unsgn(long long int nb, int base, t_params *param, int isbig)
{
	int len;
	int len_dif;

	len_dif = ft_get_len_dif(nb, base, param);
	if (!nb && !param->precision)
		len = 0 + len_dif;
	else
		len = ft_get_itoa_len_uns(nb, base) + len_dif;
	param->res = len;
	if (!param->minus && !param->zero && param->width > param->precision)
		ft_zs(param->width, ft_max(len, param->precision), 0, &(param->res));
	if (len_dif == 2 && isbig)
		ft_putstr_fd("0X", 1);
	else if (len_dif == 2)
		ft_putstr_fd("0x", 1);
	else if (len_dif == 1)
		ft_putstr_fd("0", 1);
	if (param->zero)
		ft_zs(param->width, len, 1, &(param->res));
	else if (param->precision != -1)
		ft_zs(param->precision, len - (base == 16) * len_dif, 1, &(param->res));
	if (nb || param->precision)
		ft_putnbr_base(nb, base, isbig);
	if (param->minus)
		ft_zs(param->width, ft_max(len, param->precision), 0, &(param->res));
}
