/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:32:56 by jpirsch           #+#    #+#             */
/*   Updated: 2015/05/29 19:34:05 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	ft_setenv(t_env *e)
{
	char	*env_var;

	if (e->ac == 3)
	{
		free(e->env[e->ec]);
		e->env[e->ec] = malloc(sizeof(char) * 10);
		e->env[e->ec + 1] = malloc(sizeof(char) * 1);
		e->env[e->ec + 1] = NULL;
		env_var = ft_strjoin(e->av[1], "=");
		e->env[e->ec] = ft_strjoin(env_var, e->av[2]);
		ft_putendl(e->env[e->ec]);
		e->ec++;
	}
	else
		ft_putendl_fd("Syntax error, use : setenv var value", 2);
	return (2);
}


int	ft_setenv_prog(t_env *e, char *var, char *value)
{
	char	*env_var;

	e->env[e->ec] = malloc(sizeof(char) * 10);
	e->env[e->ec + 1] = malloc(sizeof(char) * 1);
	e->env[e->ec + 1] = NULL;
	env_var = ft_strjoin(var, "=");
	e->env[e->ec] = ft_strjoin(env_var, value);
	e->ec++;
	return (2);
}

int	ft_change_env(t_env *e, char *var, char *value)
{
	char	*tmp;

	tmp = e->env[search_env(e, var)];
	tmp = ft_strsub(tmp, 0, ft_strrchr_len(tmp, '=') + 1);
	tmp = ft_strjoin(tmp, value);
	e->env[search_env(e, var)] = tmp;
	return (1);
}
