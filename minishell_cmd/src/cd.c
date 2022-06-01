/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:05:58 by gson              #+#    #+#             */
/*   Updated: 2022/06/02 02:47:37 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int cd(t_dlist *envlist, char *path)
{
    t_env	*cur_env;

    envlist->cur = envlist->head;
    while (envlist->cur != 0)
    {
        cur_env = (t_env *)envlist->cur->content;
        if (ft_strcmp(cur_env->key, "OLDPWD") == 0)
        {
            cur_env->value = getcwd(NULL, 0);
            break;
        }
        envlist->cur = envlist->cur->next;
    }
    envlist->cur = envlist->head;
    while (envlist->cur != 0)
    {
        cur_env = (t_env *)envlist->cur->content;
        if (ft_strcmp(cur_env->key, "PWD") == 0)
        {
            cur_env->value = ft_strdup(path);
            break;
        }
        envlist->cur = envlist->cur->next;
    }
    chdir(path);
    return (0);
}