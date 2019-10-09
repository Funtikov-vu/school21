/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:35:23 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 16:51:12 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int		end_type(char c)
{
	if (c == 'd' || c == 's' || c == 'c' ||
			c == 'i' || c == 'o' || c == 'u' ||
			c == 'x' || c == 'X' || c == 'p' ||
			c == 'f' || c == 'D' ||
			c == 'O' || c == 'U' || c == 'F')
		return (1);
	return (0);
}

void	ft_check_type(char *s)
{
	ft_check_old_types(s, 'D');
	ft_check_old_types(s, 'O');
	ft_check_old_types(s, 'U');
	ft_check_old_types(s, 'S');
	ft_check_old_types(s, 'C');
}

int		ft_isdigit2(int c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_check_old_types(char *s, char c)
{
	int pos;

	if ((pos = ft_strchrpos(s, c)) != -1)
	{
		s[0] = c;
		s[1] = '\0';
	}
}

char	*ft_get_output_str(t_params *param, va_list ap)
{
	char *s;

	s = 0;
	if (ft_strnchr(param->type, "cC"))
		ft_readchar(param, ap);
	else if (ft_strnchr(param->type, "Ss"))
		ft_readstr(param, ap);
	else if (ft_strchr(param->type, 'p'))
		ft_readmem(param, va_arg(ap, void*));
	else if (ft_strnchr(param->type, "diD"))
		ft_read_dec(param, ap);
	else if (ft_strnchr(param->type, "uoxXOU"))
		ft_read_unsgn(param, ap);
	else if (ft_strnchr(param->type, "fF"))
	{
		s = ft_read_float(param, ap);
		ft_putstr_fd(s, 1);
		param->res = ft_strlen(s);
		free(s);
	}
	else if (param->type[0])
		ft_printchar(param);
	return (s);
}
