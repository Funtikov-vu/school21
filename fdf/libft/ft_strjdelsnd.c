/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjdelsnd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:32:54 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/18 13:33:44 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjdelsnd(const char *str, char *str2)
{
	char *res;

	res = ft_strjoin(str, str2);
	free(str2);
	return (res);
}
