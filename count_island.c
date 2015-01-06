/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:17:39 by pxia              #+#    #+#             */
/*   Updated: 2015/01/06 11:08:20 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

static int	get_map_size(char *file)
{
	int		fd;
	int		size;
	int		ret;
	char	buffer[8192];

	size = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	size = 0;
	while ((ret = read(fd, buffer, 8191)) > 0)
		size = size + ret;
	if (ret == -1)
		return (0);
	close(fd);
	return (size);
}

static void	do_island(char *map, int rank, int largeur, int nb)
{
	if (rank >= ft_strlen(map) || map[rank] != 'X')
		return ;
	map[rank] = nb + '0';
	do_island(map, rank + 1, largeur, nb);
	do_island(map, rank + largeur, largeur, nb);
	do_island(map, rank + 1 + largeur, largeur, nb);
	do_island(map, rank + 2 + largeur, largeur, nb);
}

static void	print_island(char *map, int largeur, int hauteur)
{
	int	x;
	int	y;
	int	nb;
	int	rank;

	y = 0;
	nb = 0;
	while (y < hauteur)
	{
		x = 0;
		while (x < largeur)
		{
			rank = y * (largeur + 1) + x;
			if (map[rank] == 'X')
			{
				do_island(map, rank, largeur, nb);
				nb++;
			}
			x++;
		}
		y++;
	}
	ft_putstr(map);
}

static int	check_map(char *map)
{
	int	largeur;
	int	hauteur;
	int	i;
	int	x;

	largeur = 0;
	hauteur = 0;
	i = 0;
	x = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			hauteur++;
			if (largeur == 0)
				largeur = i;
			else if ((i - x) / largeur != hauteur)
				return (0);
			x++;
		}
		i++;
	}
	print_island(map, largeur, hauteur);
	return (1);
}

int 		count_island(char *file)
{
	char	*map;
	int		fd;
	int		ret;
	int		count;
	int		size;

	if ((size = get_map_size(file)) == 0)
		return (0);
	count = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	map = (char*)malloc(sizeof(char) * (size + 1));
	while ((ret = read(fd, map + count, 8192)) > 0)
	{
		count = count + ret;
		size = size + ret;
	}
	map[count] = '\0';
	if (ret == -1)
		return (0);
	close(fd);
	check_map(map);
	return (1);
}
