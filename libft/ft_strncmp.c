/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 06:30:28 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/05 14:33:51 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (((unsigned char *)s1)[i] && ((unsigned char *)s2)[i] && i < n)
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
	if (n - i)
	{
		if (((unsigned char *)s1)[i] == '\0' &&
				((unsigned char *)s2)[i] != '\0' && n > 0)
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		if (((unsigned char *)s2)[i] == '\0' &&
				((unsigned char *)s1)[i] != '\0' && n > 0)
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	}
	return (0);
}
