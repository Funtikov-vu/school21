/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:37:14 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 20:26:20 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <sys/acl.h>

# define SIX_MNTH 15778463
# define XATTR_SIZE 10000

typedef struct	s_fl
{
	char		*name;
	char		*pname;
	struct stat	sbuff;
	long		time;
}				t_fl;

void			read_flags(int *fl, char *str);
void			lst_print(t_list *lst, int flg, int is_dir);

int				comp_ascii(t_list *lst, t_list *lst2, int r);
int				comp_asciir(t_list *lst, t_list *lst2, int r);
int				comp_time(t_list *lst, t_list *lst2, int r);
int				comp_timer(t_list *lst, t_list *lst2, int r);
int				comp_size(t_list *lst, t_list *lst2, int r);
int				none_comp(t_list *lst, t_list *lst2, int is_r);

void			print_l(t_list *lst, int is_dir, int flg);

void			print_nb(int nb, int format);
void			print_str_r(char *str, int format);
void			print_str(char *str, int format);
void			print_name(t_fl *fl, int flg);
void			print_time(t_fl *fl);

void			print_perms(t_fl *fl, char *name);
void			print_type(t_fl *fl);
void			print_total(int *format, int is_dir, t_list *lst);

int				get_format_n_ttl(t_list *lst, int format[6]);

void			*get_comp(int fl);
t_fl			*file_gen(char *str, struct dirent *dp, int flg);
void			file_set_time(t_fl *fl, int flg);
void			del_file_lst(void *content, size_t size);

t_list			*lst_sort_add(t_list *lst, t_list *new, int flg, int is_r);
t_list			*lst_get(char *str, int flg);
t_list			*ls_dir(char *str, int flg);
void			print_error(char *name);

void			ls_arrstr(int n, char **arr, int flg);

#endif
