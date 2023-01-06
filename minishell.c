/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:42:55 by ahel-bah          #+#    #+#             */
/*   Updated: 2023/01/06 18:19:59 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

static void	check_line(char *buff, t_env *env)
{
	t_list	*arg;
	t_cmd	*cmd;

	arg = NULL;
	if (buff[0])
	{
		add_history(buff);
		if (lex(buff, &arg, env) || only_space(arg))
			ft_lstclear(&arg, free);
		else
		{
			cmd = split_pipe(arg);
			redirections_parser(cmd);
			exec_all(cmd, &env);
			signal(SIGINT, handler);
			ft_lstclear(&arg, free);
			ft_cmdclear(&cmd, free);
		}
	}
}

void	handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 1;
}

void	check_leak(void)
{
	system("leaks --list -- minishell");
}

void	main_init(int argc, char *argv[])
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_exit_status = 0;
	(void)argc;
	(void)argv;
}

int	main(int ac, char **av, char **nv)
{
	char			*buff;
	t_env			*env;
	struct termios	term;

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	main_init(ac, av);
	env = ft_env(nv);
	while (1)
	{
		buff = readline("minishell:~$ ");
		if (!buff)
		{
			ft_free_env(env);
			printf("exit\n");
			exit(0);
		}
		check_line(buff, env);
		free(buff);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (0);
}
