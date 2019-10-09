/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:10:50 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/08 13:49:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIB_H
# define FILLIB_H

int			ft_fill(int *min_sqrt, int arr[26][8], char greed[20][20],
		int count);
void		fillit(int arr[26][8], int quantity);
int			ft_sqrt(int a);
void		ft_fill_dot(char greed[20][20]);
int			ft_read_tetr(int tetrims[26][8], int fd);
void		ft_increase_y(int *x, int *y);

#endif
