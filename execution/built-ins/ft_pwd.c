/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:19:30 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/12/17 13:55:40 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_env *envp)
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
	return (0);
}