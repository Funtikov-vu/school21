/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:06:55 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/14 17:45:51 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	v_check(int *argc, char ***argv, int *vflag)
{
	*argc -= 1;
	*argv += 1;
	*vflag = 1;
}

void	check_eof(int flag, char *s)
{
	if (!flag && s != 0)
		ft_error();
}

void	f_staff(char **s, t_arrnum *a, t_arrnum *b)
{
	void	(*f)();

	f = get_f(*s);
	ft_strdel(s);
	f(a, b);
}

int		main(int argc, char **argv)
{
	t_arrnum	a;
	t_arrnum	b;
	char		*s;
	int			vflag;

	vflag = 0;
	if (ft_strequ("-v", argv[1]))
		v_check(&argc, &argv, &vflag);
	read_stacks(&a, &b, argc, argv);
	if (vflag)
		visual_checker(&a, &b);
	else
	{
		while ((vflag = get_next_line(0, &s)))
		{
			f_staff(&s, &a, &b);
		}
		check_eof(vflag, s);
		if (ft_arrnumissrt(a) && b.size == 0)
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
}
