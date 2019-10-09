/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:43:08 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 16:35:47 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		read_stacks(t_arrnum *a, t_arrnum *b, int argc, char **argv)
{
	ft_arrnumset(a, 0, 0);
	if (argc > 2)
		readnums(a, argc, argv);
	else if (argc == 2)
		split_n_read(a, argv[1]);
	else
		exit(1);
	ft_arrnumset(b, 0, 0);
	b->arr = malloc(sizeof(int) * a->size);
}

void		nb_is_new(t_arrnum arrnum, int nb)
{
	int i;

	i = 0;
	while (i < arrnum.size - 1)
	{
		if (nb == arrnum.arr[i])
			ft_error();
		i++;
	}
}

int			get_nb(char *str)
{
	long long int	nb;
	int				sgn;

	nb = 0;
	sgn = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sgn *= -1;
		str++;
	}
	if (*str == 0)
		ft_error();
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		if ((nb > 2147483647 && sgn == 1) || (nb > 2147483648 && sgn == -1))
			ft_error();
		str++;
	}
	if (*str != 0)
		ft_error();
	return (nb * sgn);
}

void		split_n_read(t_arrnum *a, char *str)
{
	char	**numbs;
	int		i;
	int		count;

	numbs = ft_strsplit(str, ' ');
	count = ft_strwrdcnt(str, ' ');
	ft_memmove(numbs + 1, numbs, count * sizeof(char*));
	readnums(a, count + 1, numbs);
	i = 1;
	while (i < count + 1)
	{
		free(numbs[i]);
		i++;
	}
	free(numbs);
}

t_arrnum	*readnums(t_arrnum *arrnum, int argc, char **argv)
{
	int			i;
	t_arrnum	*res;

	i = 1;
	res = arrnum;
	while (i < argc)
	{
		res->arr = (int*)ft_memrealloc(res->arr,
				sizeof(int) * res->size, sizeof(int) * (res->size + 1));
		res->size += 1;
		res->arr[i - 1] = get_nb(argv[i]);
		nb_is_new(*res, res->arr[i - 1]);
		i++;
	}
	return (res);
}
