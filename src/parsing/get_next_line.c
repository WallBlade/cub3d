/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:15:59 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/03 17:15:59 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int search_nl(char *line)
{
    int i = 0;

    if (!line)
        return (0);
    while (line[i])
    {
        if (line[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *clean_buf(char *buf, int red)
{
    int i;
    int len = ft_strlen(buf + red);

    i = 0;
    if (len)
        ft_strcpy(buf, buf + red, len);
    while ((i + len) < BUFFER_SIZE && buf[i + len])
    {
        buf[i + len] = '\0';
        i++;
    }
    return (buf);
}

char    *clean_line(char *line, char *buf)
{
    char *stash;
    int i = 0;
    int len = ft_strlen(line);

    while (buf && buf[i] && buf[i] != '\n')
        i++;
    if (buf[i] == '\n')
        i++;
    stash = malloc(sizeof(char) * (len + i + 1));
    if (!stash)
        return (NULL);
    stash[len + i] = '\0';
    ft_strcpy(stash, line, len);
    ft_strcpy(&stash[len], buf, i);
    clean_buf(buf, i);
    if (!stash[0])
        return (free(stash), NULL);
    return (stash);
}

int	count_lines(char *arg)
{
    int     fd;
	int		count;
	char	*line;

	count = 1;
    fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	while (count)
	{
        line = NULL;
		line = get_next_line(fd);
		if (line != NULL && line[0] != '\0' && line[0] != '\n')
			count++;
		else if (line == NULL)
			return (close(fd), count - 1);
		free(line);
	}
	return (close(fd), FALSE);
}

char *get_next_line(int fd)
{
    int red;
    char *line;
    static char buf[BUFFER_SIZE + 1];

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    line = NULL;
    red = 1;
    while (!search_nl(line) && red)
    {
        if (!buf[0])
        {
            red = read(fd, buf, BUFFER_SIZE);
            if (red < 0)
                red = 0;
            buf[BUFFER_SIZE] = '\0';
        }
        line = clean_line(line, buf);
        if (!line)
            break ;
    }
    if (!line || !line[0])
        return (free(line), NULL);
    return (line);
}