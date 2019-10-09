/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:13:32 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 20:26:10 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_nb(int nb, int format)
{
	int len;
	int i;

	len = ft_numlenbase(nb, 10);
	i = 0;
	while (i + len < format)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(nb);
}

void	print_str_r(char *str, int format)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	while (i + len < format)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
}

void	print_str(char *str, int format)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	ft_putstr(str);
	while (i + len < format)
	{
		ft_putchar(' ');
		i++;
	}
}

void	print_name(t_fl *fl, int flg)
{
	char	buf[1024];
	int		len;

	ft_putchar(' ');
	ft_putstr(fl->name);
	if ((fl->sbuff.st_mode & S_IFMT) == S_IFLNK)
	{
		ft_putstr(" -> ");
		if ((len = readlink(fl->pname, buf, sizeof(buf) - 1)) != -1)
			buf[len] = '\0';
		ft_putstr(buf);
	}
	else if ((flg & 4096) && (fl->sbuff.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('/');
}

void	print_time(t_fl *fl)
{
	char	*time_str;
	char	**temp;
	time_t	now;

	time(&now);
	time_str = ctime(&(fl->time));
	temp = ft_strsplit(time_str, ' ');
	ft_putchar(' ');
	ft_putstr(temp[1]);
	ft_putchar(' ');
	print_str_r(temp[2], 2);
	ft_putchar(' ');
	if (ft_abs(now - fl->time) < SIX_MNTH)
		ft_putnstr(temp[3], 5);
	else
	{
		ft_putchar(' ');
		ft_putnstr(temp[4], 4);
		if (ft_isalnum(temp[4][4]))
			ft_putchar(temp[4][4]);
	}
	ft_arrstrdel(temp);
}
