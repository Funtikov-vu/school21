/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:37:12 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 19:06:12 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*get_comp(int fl)
{
	if (fl & 1024)
		return (none_comp);
	else if (fl & 512)
		return (comp_size);
	if (fl & 16)
		return (comp_time);
	return (comp_ascii);
}

void	file_set_time(t_fl *fl, int flg)
{
	if (flg & 64)
		fl->time = fl->sbuff.st_birthtimespec.tv_sec;
	else if (flg & 128)
		fl->time = fl->sbuff.st_ctimespec.tv_sec;
	else if (flg & 256)
		fl->time = fl->sbuff.st_atimespec.tv_sec;
	else
		fl->time = fl->sbuff.st_mtimespec.tv_sec;
}

t_fl	*file_gen(char *str, struct dirent *dp, int flg)
{
	t_fl *fl;

	fl = (t_fl*)malloc(sizeof(t_fl));
	fl->name = ft_strdup(dp->d_name);
	fl->pname = ft_strjoin(str, dp->d_name);
	lstat(fl->pname, &fl->sbuff);
	file_set_time(fl, flg);
	return (fl);
}

void	del_file_lst(void *content, size_t size)
{
	t_fl *fl;

	fl = content;
	free(fl->name);
	free(fl->pname);
	free(fl);
	size = 42;
}
