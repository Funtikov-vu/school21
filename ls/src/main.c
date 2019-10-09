/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:41:57 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 18:46:34 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *name)
{
	char *temp;

	if (name[0] == 0)
	{
		temp = ft_strdup("ls: open");
		perror(temp);
		exit(1);
	}
	temp = ft_strjoin("ls: ", name);
	perror(temp);
	free(temp);
}

int		norm_flag(int flg)
{
	if (flg & 1024)
		flg |= 4;
	return (flg);
}

int		main(int argc, char **argv)
{
	int flags;
	int i;

	flags = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && !ft_strequ("-", argv[i]))
	{
		if (ft_strequ("--", argv[i]))
		{
			i++;
			break ;
		}
		read_flags(&flags, (argv[i] + 1));
		i++;
	}
	flags = norm_flag(flags);
	if (flags & 32 && flags & 512)
		flags &= 0xffffffef;
	if (i == argc)
		ls_dir(".", flags);
	else
		ls_arrstr(argc - i, argv + i, flags);
}
