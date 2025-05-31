/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:28:17 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/31 14:34:23 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	elements_pos(t_game **pos)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = len_y((*pos)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*pos)->map->map[map.y][map.x] != '\0')
		{
			if ((*pos)->map->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*pos)->map->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*pos)->map->map[map.y][map.x] == 'E')
				map.e++;
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.p == 0)
		perror("Map error\n");
}

char	**get_map(char *map)
{
	char	*line;
	char	*lines;
	int		fd;

	line = "";
	lines = ft_strdup("");
	fd = open(map, O_RONDLY);
	if (fd < 0)
		perror("Can't open file\n");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		lines = ft_strjoin(lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (lines[0] == '\0')
		perror("Bad map\n");
	return (ft_split(lines, '\n'));
}
