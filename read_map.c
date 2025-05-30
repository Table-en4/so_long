/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:28:17 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/30 18:49:54 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	read_map(int fd, t_game game, char **av)
{
	int	i;
	static char	*line;

	if (!av[1][i])
		return ;
	fd = open(av[1][i], O_RONDLY);
	if (fd < 0)
		return (perror("Error can't open file"), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[i] == 'P')
			return ;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(0);
	return ;
}
