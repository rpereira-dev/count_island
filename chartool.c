/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:46:57 by pxia              #+#    #+#             */
/*   Updated: 2015/01/06 10:47:19 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}


