/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:30:36 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/12 14:28:32 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		check_builtin(t_env *e)
{
	int		ret;

	if (!e->av[0])
		return (0);
	ret = (ft_strequ(e->av[0], "env") && !(e->av[1])) ? display_env(e) : 0;
	if (ret != 2)
		ret = (ft_strequ(e->av[0], "cd")) ? ft_cd(e) : 0;
	if (ret != 2)
		ret = (ft_strequ(e->av[0], "setenv")) ? ft_setenv(e) : 0;
	if (ret != 2)
		ret = (ft_strequ(e->av[0], "unsetenv")) ? ft_unsetenv(e) : 0;
	if (ret != 2)
		ret = (!(ft_strncmp(e->av[0], "./", 2))) ? ft_exec(e) : 0;
	if (ret != 2)
		ret = (ft_strcmp(e->av[0], "exit")) ? 0 : 1;
	return (ret);
}

int		cmd_to_env(char *line, t_env *e)
{
	if (line && line[0])
	{
		if (ft_strchr_len(line, ';'))
		{
			e->save = ft_strchr(line, ';');
			line = ft_strsub(line, 0, ft_strchr_len(line, ';'));
		}
		line = ft_strtrim(line);
		if (!line[0])
			return (0);
		//strsplit cmd avec ;
		e->ac = ft_countwords(line, ' ');
		e->av = ft_strsplit(line, ' ');
		return (1);
	}
	else
		return (0);
}

int		check_cmd(char *line, t_env *e)
{
	int		ret;
	int		i;

	if (cmd_to_env(line, e))
	{
		ret = check_builtin(e);
		(ret == 2 || ret == 1) ? 1 : check_path(e);
		return (ret);
	}
	else
	{
		ft_putendl_fd("Error while splitting command", 2);
		return (0);
	}
}
