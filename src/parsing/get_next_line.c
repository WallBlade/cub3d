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

char	*ft_clean(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = 0;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stash[i] && buf[j])
		buf[j++] = stash[i++];
	buf[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			res;
	char		*line;
	char		*stash;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	res = BUFFER_SIZE;
	stash = NULL;
	stash = ft_strjoin(stash, buf);
	while (res == BUFFER_SIZE && !ft_strchr(buf))
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
			return (free(stash), NULL);
		buf[res] = '\0';
		if (res == 0 && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin(stash, buf);
	}
	line = ft_clean(stash, buf);
	return (free(stash), line);
}