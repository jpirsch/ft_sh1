/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 05:11:10 by jpirsch           #+#    #+#             */
/*   Updated: 2015/06/14 11:56:55 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void	prompt(t_env *e)
{
	char *pwd;
	char *user;

	user = get_env(e, "USER");
	pwd = get_env(e, "PWD");
	if (user[0] != '_')
	{
		ft_putstr(C_RED);
		ft_putstr(user);
	}
	ft_putstr(C_BLUE);
	ft_putstr("@");
	if (pwd[0] != '_')
	{
		ft_putstr(C_BROWN);
		ft_putstr(pwd);
	}
	ft_putstr(C_NONE);
	ft_putstr("/>");
}

void	ft_free(t_env *e)
{
	int	i;

	i = -1;
	if (e)
	{
		if (e->av)
			while (++i < e->ac)
				free(e->av[i]);
		free(e->av);
		free(e);
	}
}

void	catch(int signum)
{
	ft_putstr("\b\b");
}

int		ft_putc(int c)
{
	write(1, &c, 1);
	return (0);
}

static void	initialize_terminal(char **av)
{
	char		*term;
	t_termios	s_term;

	term = getenv("TERM");
	if (!term)
		exit(EXIT_FAILURE);
	tgetent(NULL, term);
	tcgetattr(0, &s_term);
	s_term.c_lflag &= ~(ICANON);
	s_term.c_lflag &= ~(ECHO);
	s_term.c_cc[VMIN] = 1;
	s_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &s_term);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
}

void	restore_term(int success)
{
	t_termios	s_term;

	tcgetattr(0, &s_term);
	s_term.c_lflag |= (ICANON);
	s_term.c_lflag |= (ECHO);
	tcsetattr(0, TCSADRAIN, &s_term);
	if (success != -42)
		tputs(tgetstr("cl", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	exit(EXIT_SUCCESS);
}

int		main(int ac, char **av, char **env)
{
	char			buf[4];
	char			*line;
	int				ret;
	int				x;
	int				fd;
	t_termios		*term;
	t_env 			*e;

	ret = 0;
	e = (!(env[0])) ? empty_env() : init_env(env);
	signal(SIGINT, catch);
//	initialize_terminal(av);
	while (ret != 1)
	{
		prompt(e);
		if (get_next_line(0, &line))
		{
			ret = check_cmd(line, e);
			if (ret == 1)
				break ;
		}
	}
//	restore_term(1);
	ft_free(e);
	return (0);
}
	/*
//	while (ret != 1)
	{//
		line = ft_strdup("");
		prompt(e);
		while (buf[0] != 4)			
		{
			ft_bzero(buf, 4);
			read(0, buf, 4);
			x = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
			if (x == 10)
			{
				ft_putchar('\n');
				ft_putstr(line);
				ret = check_cmd(line, e);
				free(line);
				line = NULL;
				line = ft_strdup("");
				if (ret == 1)
					break ;
				prompt(e);
			}
			else if (ft_isprint(x))
			{
				ft_putchar(buf[0]);
				line = ft_strjoin(line, buf);
			}
			else if (x == 9)
			{
				ft_putnbr(x);
			}
		}
//	}
	restore_term(1);
	ft_free(e);
	return (0);
}*/
