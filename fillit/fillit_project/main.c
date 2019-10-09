/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:05:40 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/08 13:50:04 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillib.h"

int		ft_usage(void)
{
	ft_putendl("usage: fillit source_file");
	return (1);
}

int		ft_error(void)
{
	ft_putendl("error");
	return (1);
}

int		main(int argc, char **argv)
{
	int	tetrims[26][8];
	int	count;
	int	fd;

	if (argc > 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	if (!(count = ft_read_tetr(tetrims, fd)))
	{
		close(fd);
		return (ft_error());
	}
	close(fd);
	fillit(tetrims, count);
	return (1);
}
