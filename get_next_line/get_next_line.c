/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:08:33 by ttavares          #+#    #+#             */
/*   Updated: 2023/10/30 11:44:24 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/* Formats stash to remove previous recovered line, keeping
only the necessary excess after \n for next get_next_line call */

char	*format_stash(char	*stash)
{
	int		i;
	int		stashlenght;
	char	*formatedstash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (0);
	}
	stashlenght = ft_strlen_gnl(stash);
	formatedstash = malloc (sizeof(char) * (stashlenght - i + 1));
	if (!formatedstash)
		return (0);
	i++;
	ft_strlcpy_gnl(formatedstash, stash + i, stashlenght - i + 1);
	free (stash);
	return (formatedstash);
}

/* Retrieves a formated line from the stashed buffer*/

char	*format_line(char *stash)
{
	int		i;
	char	*formatedline;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	formatedline = malloc (sizeof(char) * (i + 1));
	if (!formatedline)
		return (0);
	ft_strlcpy_gnl(formatedline, stash, i + 1);
	return (formatedline);
}

/*Reads and stashes function in static var while no new line is found*/

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytesread;

	bytesread = 1;
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (find_linebreaker(stash) == 0 && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[bytesread] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_stash(fd, stash);
	if (!stash)
		return (0);
	line = format_line(stash);
	stash = format_stash(stash);
	return (line);
}
