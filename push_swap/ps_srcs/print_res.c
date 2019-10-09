/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:31:26 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/13 14:12:47 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		arr_str_len(char **temp)
{
	int i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int		is_nothing(const char *str1, const char *str2)
{
	if (ft_strequ("pb", str1) && ft_strequ("pa", str2))
		return (1);
	if (ft_strequ("pa", str1) && ft_strequ("pb", str2))
		return (1);
	if (ft_strequ("ra", str1) && ft_strequ("rra", str2))
		return (1);
	if (ft_strequ("rra", str1) && ft_strequ("ra", str2))
		return (1);
	if (ft_strequ("rb", str1) && ft_strequ("rrb", str2))
		return (1);
	if (ft_strequ("rrb", str1) && ft_strequ("rb", str2))
		return (1);
	return (0);
}

int		is_rr(const char *str1, const char *str2)
{
	if (ft_strequ("ra", str1) && ft_strequ("rb", str2))
		return (1);
	if (ft_strequ("rb", str1) && ft_strequ("ra", str2))
		return (1);
	return (0);
}

void	clear_temp_arr(char **temp, int len)
{
	int i;
	int j;
	int flag;

	i = -1;
	while (++i < len)
		if (temp[i])
		{
			j = i + 1;
			while (!temp[j] && j < len)
				j++;
			if (temp[j] && ((flag = is_rr(temp[i], temp[j])) ||
						is_nothing(temp[i], temp[j])))
			{
				free(temp[i]);
				free(temp[j]);
				temp[i] = 0;
				temp[j] = 0;
				if (flag)
					temp[i] = ft_strdup("rr");
				i -= 2;
			}
		}
}

void	smart_print(char *str)
{
	char	**temp;
	int		i;
	int		len;

	i = 0;
	temp = ft_strsplit(str, ' ');
	len = arr_str_len(temp);
	clear_temp_arr(temp, len);
	i = 0;
	while (i < len)
	{
		if (temp[i])
		{
			ft_putendl(temp[i]);
			free(temp[i]);
		}
		i++;
	}
	free(temp);
}
