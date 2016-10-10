/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 08:41:37 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/17 18:30:00 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	change_pwd(t_env *e, char *pwd)
{
	if (search_env(e, "OLDPWD") == -1)
		ft_setenv_prog(e, "OLDPWD", get_env(e, "PWD"));
	else
		ft_change_env(e, "OLDPWD", get_env(e, "PWD"));
	ft_change_env(e, "PWD", pwd);
}

void	set_pwd(t_env *e, char **pwd)
{
	if (e->ac == 2)
	{
		if (!(ft_strcmp(e->av[1], "-")))
		{
			if (search_env(e, "OLDPWD") == -1)
				ft_putendl_fd("minishell1 : cd : OLDPWD not set", 2);
			else
				*pwd = get_env(e, "OLDPWD");
		}
		else if (!(ft_strcmp(e->av[1], "..")))
			*pwd = ft_strsub(get_env(e, "PWD"),
				0, ft_strrchr_len(get_env(e, "PWD"), '/'));
		else if (!(ft_strcmp(e->av[1], ".")))
			*pwd = get_env(e, "PWD");
		else if (!(ft_strcmp(e->av[1], "~")))
			*pwd = get_env(e, "HOME");
		else if (e->av[1][0] == '/')
			*pwd =  e->av[1];
		else
			*pwd = ft_strjoin(
				ft_strjoin(get_env(e, "PWD"), "/"), e->av[1]);
	}
	else if (e->ac == 1)
		*pwd = get_env(e, "HOME");
}

int		ft_cd(t_env *e)
{
	char	*pwd;

	set_pwd(e, &pwd);
	if ((chdir(pwd)) == -1)
		ft_putendl_fd("No such file or directory", 2);
	else
		change_pwd(e, pwd);
	return (2);
}
