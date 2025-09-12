/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:03:00 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 09:58:27 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*final;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	final = (char *)malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	while (s[i])
	{
		final[i] = (*f)(i, s[i]);
		i++;
	}
	final[i] = 0;
	return (final);
}
