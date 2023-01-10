/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:14:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:48:47 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_env *envp)
{
	t_env	*env;
	char	*pwd;

	env = envp;
	pwd = NULL;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		pwd = ft_getenv(env, "PWD");
		printf("%s\n", pwd);
	}
	else
	{
		printf("%s\n", pwd);
		free(pwd);
	}
}
