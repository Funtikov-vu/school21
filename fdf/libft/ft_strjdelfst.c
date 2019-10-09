/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjdelfst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:48:56 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/15 13:51:04 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjdelfst(char *str, const char *str2)
{
	char *res;

	res = ft_strjoin(str, str2);
	free(str);
	return (res);
}
