/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:24:02 by gson              #+#    #+#             */
/*   Updated: 2022/05/30 22:20:10 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	env(t_dlist *envlist)
{
	t_env	*cur_env;

	envlist->cur = envlist->head;
	while (envlist->cur != 0)
	{
		cur_env = (t_env *)envlist->cur->content;
		if (cur_env->has_equal != -1)
		{
			if (cur_env->value == NULL)
				printf("%s=\n", cur_env->key);
			else
				printf("%s=%s\n", cur_env->key, cur_env->value);
		}
		envlist->cur = envlist->cur->next;
	}
	return (0);
}
