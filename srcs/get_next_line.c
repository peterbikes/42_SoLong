/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:57:04 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:12:42 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_to_fdarr(int fd, char *fdarr);

char	*line_or_eof(char *fdarr);

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(char *str);

char	*set_fdarr(char *fdarr);

char	*get_next_line(int fd)
{
	char		*print;
	static char	*fdarr [10000];

	if (fd < 0 || 1000 <= 0)
		return (0);
	fdarr[fd] = read_to_fdarr(fd, fdarr[fd]);
	if (!fdarr[fd])
		return (NULL);
	print = line_or_eof(fdarr[fd]);
	fdarr[fd] = set_fdarr(fdarr[fd]);
	return (print);
}

char	*read_to_fdarr(int fd, char *fdarr)
{
	char	*buffer;
	int		nbr;

	buffer = malloc((1000 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nbr = 1;
	while (!ft_strchr(fdarr, '\n') && nbr != 0)
	{
		nbr = read(fd, buffer, 1000);
		if (nbr == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbr] = '\0';
		fdarr = ft_strjoin(fdarr, buffer);
	}
	free(buffer);
	return (fdarr);
}

char	*line_or_eof(char *fdarr)
{
	int		i;
	char	*print;

	i = 0;
	if (!fdarr[i])
		return (NULL);
	while (fdarr[i] != '\0' && fdarr[i] != '\n')
		i++;
	print = (char *)malloc(sizeof(char) * (i + 2));
	if (!print)
		return (NULL);
	i = 0;
	while (fdarr[i] != '\0' && fdarr[i] != '\n')
	{
		print[i] = fdarr[i];
		i++;
	}
	if (fdarr[i] == '\n')
	{
		print[i] = '\n';
		i++;
	}
	print[i] = '\0';
	return (print);
}

char	*set_fdarr(char *fdarr)
{
	int		i;
	int		k;
	char	*temp;

	i = 0;
	k = 0;
	while (fdarr[i] != '\0' && fdarr[i] != '\n')
		i++;
	if (!fdarr[i])
	{
		free(fdarr);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(fdarr) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (fdarr[i])
		temp[k++] = fdarr[i++];
	temp[k] = '\0';
	free(fdarr);
	return (temp);
}
