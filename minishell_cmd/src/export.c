/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leafmire <leafmire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:29:37 by gson              #+#    #+#             */
/*   Updated: 2022/05/31 02:49:44 by leafmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	is_contain_specialCharacter(char *str)
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

int	check_identifier_first(char identifier)
{
	if (identifier == '_')
		return (0);
	if ((identifier >= 65 && identifier <= 90)
		|| (identifier >= 97 && identifier <= 122))
		return (1);
	return (-1);
}

int	check_arg_error(char **element, char *argv)
{
	if (check_identifier_first(element[0][0]) == -1)
	{
		printf("export: `%s': not a valid identifier\n", argv);
		return (-1);
	}
	if (check_identifier_first(element[0][0]) == 0
		&& ft_strlen(element[0]) == 1)
		return (-1);
	if (is_contain_specialCharacter(element[0]) == -1)
	{
		printf("export: `%s': not a valid identifier\n", argv);
		return (-1);
	}
	return (0);
}

int	export_args(t_dlist *envlist, char *argv)
{
	t_env	*new_env;
	t_env	*temp_env;
	char	**element;

	element = ft_split(argv, "=");
	if (check_arg_error(element, argv) == -1)
		return (-1);
	new_env = malloc(sizeof(t_env));
	new_env->key = element[0];
	if (element[1] != 0)
	{
		new_env->value = element[1];
		new_env->has_equal = 1;
	}
	else if (ft_strchr(argv, '=') == NULL)
	{
		new_env->value = NULL;
		new_env->has_equal = 0;
	}
	else
	{
		new_env->value = NULL;
		new_env->has_equal = -1;
	}
	push_back(envlist, new_env);
	temp_env = envlist->tail->content;
	envlist->tail->content = envlist->tail->prev->content;
	envlist->tail->prev->content = temp_env;
	return (0);
}

int	export_no_args(t_dlist *envlist)
{
	t_dlist	*cp_envlist;
	t_env	*cur_env;

	cp_envlist = duplicate_dlist(envlist);
	mergesort_dlist(cp_envlist, key_compare);
	cp_envlist->cur = cp_envlist->head;
	while (cp_envlist->cur != 0)
	{
		cur_env = (t_env *)cp_envlist->cur->content;
		if (cur_env->has_equal == 1)
			printf("declare -x %s=\"%s\"\n", cur_env->key, cur_env->value);
		else if (cur_env->has_equal == 0)
			printf("declare -x %s=\"\"\n", cur_env->key);
		else if (cur_env->has_equal == -1)
			printf("declare -x %s\n", cur_env->key);
		cp_envlist->cur = cp_envlist->cur->next;
	}
	return (0);
}

int	export(t_dlist *envlist, int argc, char **argv)
{
	int		i;

	if (argc == 2)
		export_no_args(envlist);
	else if (argc > 2)
	{
		i = 2;
		while (argv[i] != 0)
		{
			export_args(envlist, argv[i]);
			i++;
		}
	}
	return (0);
}
