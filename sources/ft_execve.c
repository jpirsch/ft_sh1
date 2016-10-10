/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:33:37 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/29 15:57:06 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh1.h"

int		ft_exec(t_env *e)
{
	ft_execve(ft_strchr(e->av[0], '/') + 1, e->av, e->env);
	return (2);
}

void	ft_execve(char *cmd, char **av, char **env)
{
	pid_t	father;

	if (cmd != NULL)
	{
		father = fork();
		if (father > 0)
			wait(NULL);
		if (father == 0)
		{
			signal(SIGINT, SIG_DFL);
			execve(cmd, av, env);
			exit(EXIT_FAILURE);
		}
	}
}
