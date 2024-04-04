/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:10:23 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/04 17:34:42 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdir(char *path, int flags, int perms)
{
	int		fd;
	char	c[1];

	fd = open(path, flags, perms);
	if (fd != -1 && read(fd, c, 1) < 0)
	{
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}
