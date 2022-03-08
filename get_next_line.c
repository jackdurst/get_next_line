/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurst <jdurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:55:10 by jdurst            #+#    #+#             */
/*   Updated: 2022/03/08 16:35:15 by jdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*  */

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char *save;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save)
}

/* Votre programme doit compiler avec l’option : -D BUFFER_SIZE=n
Cette macro définie à l’invocation du compilateur servira à spécifier la taille du
buffer lors de vos appels à read() dans votre fonction get_next_line().
Cette valeur sera modifiée lors de la peer-evaluation et par la Moulinette dans le
but de tester votre rendu.

https://github.com/eliarisalvares/get_next_line_42sp

-D<macroname>=<value>

Adds an implicit #define into the predefines buffer which is read before the source file is preprocessed. */
