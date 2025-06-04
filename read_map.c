/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:28:17 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/04 13:12:58 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

char	*copy_line(char *line)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = line[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	load_map(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	map->y = get_map_height(file);
	map->map = malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map[i] = copy_line(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	map->x = t_strlen(map->map[0]);
	close(fd);
	return (0);
}

