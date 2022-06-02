/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:35:30 by gson              #+#    #+#             */
/*   Updated: 2022/06/02 23:32:47 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int	is_contain_specialCharacter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] >= 65 && str[i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122)
			|| (str[i] >= 48 && str[i] <= 57)
			|| (str[i] == '_'))
			i++;
		else
			return (-1);
	}
	return (0);
}

static int	check_identifier_first(char identifier)
{
	if (identifier == '_')
		return (0);
	if ((identifier >= 65 && identifier <= 90)
		|| (identifier >= 97 && identifier <= 122))
		return (1);
	return (-1);
}

static int	check_arg_error(char *argv)
{
	if (check_identifier_first(argv[0]) == -1)
	{
		printf("unset: `%s': not a valid identifier\n", argv);
		return (-1);
	}
	if (check_identifier_first(argv[0]) == 0
		&& ft_strlen(argv) == 1)
		return (-1);
	if (is_contain_specialCharacter(argv) == -1)
	{
		printf("unset: `%s': not a valid identifier\n", argv);
		return (-1);
	}
	return (0);
}

int	unset_arg(t_dlist *envlist, char *argv)
{
	t_env	*cur_env;

	if (check_arg_error(argv) == -1)
		return (-1);
	envlist->cur = envlist->head;
	while (envlist->cur != 0)
	{
		cur_env = (t_env *)envlist->cur->content;
		if (ft_strcmp(cur_env->key, argv) == 0)
		{
			if (envlist->cur == envlist->head)
				pop_front(envlist, &delete_content);
			if (envlist->cur == envlist->tail)
				pop_back(envlist, &delete_content);
			else
				pop_node(envlist, envlist->cur, &delete_content);
			return (0);
		}
		envlist->cur = envlist->cur->next;
	}
	return (0);
}

int	unset(t_dlist *envlist, int argc, char **argv)
{
	int	i;

	if (argc == 2)
		return (0);
	else if (argc > 2)
	{
		i = 2;
		while (i < argc)
		{
			unset_arg(envlist, argv[i]);
			i++;
		}
	}
	return (0);
}
