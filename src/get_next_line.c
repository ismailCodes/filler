/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:02:07 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 23:15:41 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		get_next_line(const int fd, char **line)
{
	static char	*ptr;
	char		*tmp;
	int			rd;
	char		bfr[BUFF_SIZE + 1];

	ptr = (!ptr) ? "" : ptr;
	while ((rd = read(fd, bfr, BUFF_SIZE)))
	{
		bfr[rd] = '\0';
		tmp = ptr;
		ptr = ft_strjoin(ptr, bfr);
		(ft_strlen(tmp) != 0) ? free(tmp) : 0;
		if (ft_strchr(ptr, '\n'))
			break ;
	}
	rd = 0;
	if (ptr[0] == '\0')
		return (0);
	while (ptr[rd] && ptr[rd] != '\n')
		rd++;
	*line = ft_strsub(ptr, 0, rd);
	tmp = ptr;
	ptr = (ft_strchr(ptr, ptr[rd]) + 1);
	free(tmp);
	return (1);
}
