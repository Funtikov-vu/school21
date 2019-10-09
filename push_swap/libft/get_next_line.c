/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:22:51 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/14 17:48:31 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_line(char **line, char *buf)
{
	char	*pos;
	int		end;
	int		res;
	int		len;

	res = 0;
	if ((pos = ft_strchr(buf, '\n')))
	{
		end = pos - buf;
		res = 1;
	}
	else
		end = ft_strlen(buf);
	if (end > 0)
	{
		len = ft_strlen(*line) + end + 1;
		*line = (char *)ft_myrealloc(*line, len);
		if (!*line)
			return (-1);
		ft_strlcat(*line, buf, len);
	}
	res == 1 ? ft_memmove(buf, buf + end + 1, BUFF_SIZE - end) : ft_strclr(buf);
	return (res);
}

static int	ft_clear_all(char **line, int ret)
{
	if (!ret && **line != 0)
		return (0);
	ft_strdel(line);
	if (!ret)
		return (0);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		buf[BUFF_SIZE] = "";
	int				exit;

	exit = 0;
	if (fd < 0 || line == 0)
		return (-1);
	*line = ft_strdup("");
	if (buf[0] && line && fd >= 0)
		exit = add_line(line, buf);
	while (!exit && ((ret = read(fd, buf, BUFF_SIZE)) >= 0))
	{
		if (ret == 0)
			return (ft_clear_all(line, ret));
		buf[ret] = '\0';
		exit = add_line(line, buf);
	}
	if (exit == -1 || ret < 0)
		return (ft_clear_all(line, ret));
	return (1);
}
