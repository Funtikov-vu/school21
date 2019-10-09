/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_perms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:22:42 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/29 19:56:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total(int *format, int is_dir, t_list *lst)
{
	int total;

	ft_memset(format, 0, 6 * sizeof(int));
	total = get_format_n_ttl(lst, format);
	if (is_dir && lst)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

void	print_type(t_fl *fl)
{
	int ftype;

	ftype = fl->sbuff.st_mode & S_IFMT;
	if (ftype == S_IFBLK)
		ft_putchar('b');
	else if (ftype == S_IFCHR)
		ft_putchar('c');
	else if (ftype == S_IFDIR)
		ft_putchar('d');
	else if (ftype == S_IFIFO)
		ft_putchar('p');
	else if (ftype == S_IFREG)
		ft_putchar('-');
	else if (ftype == S_IFLNK)
		ft_putchar('l');
	else if (ftype == S_IFSOCK)
		ft_putchar('s');
}

void	print_acl(t_fl *fl, char *name)
{
	int			x;
	acl_t		acl;
	acl_entry_t	dummy;

	acl = NULL;
	acl = acl_get_link_np(fl->pname, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	x = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
	if (x > 0)
		ft_putchar('@');
	else if (acl != NULL)
		ft_putchar('+');
	else
		ft_putchar(' ');
}

void	print_perms(t_fl *fl, char *name)
{
	unsigned short	temp;
	char			buff[10];

	temp = fl->sbuff.st_mode;
	buff[0] = ((fl->sbuff.st_mode & S_IRUSR) ? 'r' : '-');
	buff[1] = ((fl->sbuff.st_mode & S_IWUSR) ? 'w' : '-');
	buff[2] = ((fl->sbuff.st_mode & S_IXUSR) ? 'x' : '-');
	buff[3] = ((fl->sbuff.st_mode & S_IRGRP) ? 'r' : '-');
	buff[4] = ((fl->sbuff.st_mode & S_IWGRP) ? 'w' : '-');
	buff[5] = ((fl->sbuff.st_mode & S_IXGRP) ? 'x' : '-');
	buff[6] = ((fl->sbuff.st_mode & S_IROTH) ? 'r' : '-');
	buff[7] = ((fl->sbuff.st_mode & S_IWOTH) ? 'w' : '-');
	buff[8] = ((fl->sbuff.st_mode & S_IXOTH) ? 'x' : '-');
	if (fl->sbuff.st_mode & S_ISVTX)
		buff[8] = (buff[8] == 'x' ? 't' : 'T');
	if (fl->sbuff.st_mode & S_ISGID)
		buff[5] = (buff[5] == 'x' ? 's' : 'S');
	if (fl->sbuff.st_mode & S_ISUID)
		buff[2] = (buff[2] == 'x' ? 's' : 'S');
	buff[9] = 0;
	ft_putstr(buff);
	print_acl(fl, name);
}
