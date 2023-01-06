/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:33:27 by ahel-bah          #+#    #+#             */
/*   Updated: 2023/01/06 14:45:15 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		if (env->content)
			free(env->content);
		free(env->name);
		env = env->next;
		free(tmp);
	}
}

void	print_env(t_env *env)
{
	while (env != NULL)
	{
		if (env->content && env->name && ft_strcmp(env->name, "SPATH"))
		{
			printf("%s", env->name);
			printf("=");
			printf("%s\n", env->content);
		}
		env = env->next;
	}
}

int	ft_env_cmd(t_env *env, char **content)
{
	if (ft_dubstrlen(content) > 1)
	{
		write(2, "env: ", 5);
		write(2, content[1], ft_strlen(content[1]));
		write(2, ": No such file or directory\n", 28);
		g_exit_status = 1;
		return (0);
	}
	else
		print_env(env);
	return (0);
}

static int	ft_start(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '=')
			return (i);
	}
	return (0);
}

t_env	*ft_env(char **nv)
{
	int		i;
	int		tmp;
	int		start;
	t_env	*env;

	i = -1;
	env = NULL;
	while (nv[++i])
	{
		start = ft_start(nv[i]);
		ft_envadd_back(&env, ft_envnew(ft_substr_lex(nv[i], start,
					ft_strlen(nv[i])), ft_substr_lex(nv[i], 0, start - 1)));
		if (ft_strcmp(ft_envlast(env)->name, "SHLVL") == 0)
		{
			tmp = ft_atoi(ft_envlast(env)->content) + 1;
			free(ft_envlast(env)->content);
			ft_envlast(env)->content = ft_itoa(tmp);
		}
	}
	ft_envadd_back(&env, ft_envnew(ft_strdup(PATH),
			ft_strdup("SPATH")));
	return (env);
}
