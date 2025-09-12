/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:10:23 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 10:52:31 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
