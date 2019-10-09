/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:13:40 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 17:03:46 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int		ft_toup(long double nb, int n, long double eps)
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
		{
			if (nb * ft_pow(10L, ++i - 1) >= eps)
			{
				res += 1;
				nb -= 10L * temp;
			}
		}
	}
	if (res > 5 || (res == 5 && nb > 0))
		return (1);
	else
		return (0);
}

char	*ft_read_fract_float(long double *nb, long double eps)
{
	int			digit;
	long double	temp;
	int			res;
	char		*s;
	long double	n;

	n = *nb;
	digit = ft_count_float_digit(n);
	s = ft_strdup("");
	while (digit != -1)
	{
		temp = ft_pow(10L, digit);
		res = (n / temp);
		n -= temp * res;
		if (n >= eps)
		{
			res += 1;
			n -= 1.0L;
		}
		s = ft_add_char(s, '0' + (int)res);
		digit--;
	}
	*nb = n;
	return (s);
}

char	*ft_read_int_float(long double *nb)
{
	int			digit;
	long double	temp;
	int			res;
	char		*s;
	long double	n;

	n = *nb;
	res = 1;
	temp = 1.0;
	digit = ft_count_float_digit(n);
	s = ft_strdup("");
	while (digit != -1)
	{
		temp = ft_pow(10L, digit);
		res = (n / temp);
		n -= temp * res;
		s = ft_add_char(s, '0' + (int)res);
		digit--;
	}
	*nb = n;
	return (s);
}

char	*ft_readfloat(long double nb, int prec, char c)
{
	char		*s1;
	long double	eps;
	char		sgn;
	int			i;

	ft_sub_float(&sgn, &eps, c, &i);
	if (nb < 0)
	{
		nb = 0 - nb;
		sgn = '-';
	}
	if (ft_toup(nb, prec + 1, eps) == 1)
		nb = nb + ft_pow(10, 0 - prec);
	s1 = ft_read_int_float(&nb);
	s1 = ft_add_char(s1, '.');
	while (i < prec)
	{
		nb *= 10L;
		s1 = ft_add_char(s1, *(ft_read_fract_float(&nb, eps)));
		i++;
	}
	if (sgn)
		s1 = ft_addr_char(s1, sgn);
	return (s1);
}

char	*ft_read_float(t_params *param, va_list ap)
{
	char	*s;
	int		len;

	if (param->precision == -1)
		param->precision = 6;
	if (ft_strequ(param->type, "f") || ft_strequ(param->type, "F"))
		s = ft_readfloat(va_arg(ap, double), param->precision, 'f');
	else
		s = ft_readfloat(va_arg(ap, long double), param->precision, 'L');
	if (param->plus && *s != '-')
		s = ft_strjdelsnd("+", s);
	else if (param->space && *s != ' ')
		s = ft_strjdelsnd(" ", s);
	len = ft_strlen(s);
	s = ft_width(param, s, &len);
	return (s);
}
