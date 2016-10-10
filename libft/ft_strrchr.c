/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 03:20:08 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 14:29:19 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	//ft_putchar('7');
	n = ft_strlen((char*)s);
//	ft_putstr("yoloswag");
	s += n;
	while (n + 1)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		n--;
	}
	return (NULL);
}
