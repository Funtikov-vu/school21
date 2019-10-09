/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:15:05 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/14 17:56:23 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_arrnum a;
	t_arrnum b;

	if (argc == 1)
		return (0);
	read_stacks(&a, &b, argc, argv);
	push_swap(&a, &b);
}
