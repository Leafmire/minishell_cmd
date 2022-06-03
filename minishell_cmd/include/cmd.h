/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:27:00 by gson              #+#    #+#             */
/*   Updated: 2022/06/03 18:24:12 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/errno.h>
# include "../doubly_linked_list/dlinkedlist.h"

typedef struct s_env {
	char			*key;
	char			*value;
	int				has_equal;
}	t_env;

char		**ft_split(const char *str, const char *delim);
char		**ft_split_first(const char *str, const char *delim);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strndup(const char *src, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
void		delete_content(void *env);
int			key_compare(void *node1, void *node2);
int			env(t_dlist *envlist, int argc, char **argv);
int			cd(t_dlist *envlist, int argc, char **argv);
int			export(t_dlist *envlist, int argc, char **argv);
int			unset(t_dlist *envlist, int argc, char **argv);
int			echo(char **argv);
int			builtin_exit(t_dlist *envlist, int argc, char **argv);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
long long	ft_atoll(char *str, int *error);
int			is_contain_special(char *str);
int			check_identifier_first(char identifier);
#endif
