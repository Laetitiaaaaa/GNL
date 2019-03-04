/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 08:13:33 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/04 15:48:12 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;
	char *line;
	int i;
	int	res;

	i = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
//	get_next_line(fd, &line);
//	printf("line = %s\n", line);
//	free(line);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("%d: %s\n", res, line);
		free(line);
		line = NULL;
	}
	printf("%d: %s\n", res, line);
	close(fd);
	return (0);
}
