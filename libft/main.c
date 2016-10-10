/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 01:01:55 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/08 01:11:16 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av, char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], "PATH", 4)))
			break ;
		i++;
	}
	path = ft_strsplit(env[i] + 5, ':');
	ft_putnbr(i);
	ft_putchar(' ');
	ft_putnbr(ft_countwords(env[i], ':'));
	ft_putendl(path[0]);
	return (0);
}
