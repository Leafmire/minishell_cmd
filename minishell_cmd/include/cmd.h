/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:27:00 by gson              #+#    #+#             */
/*   Updated: 2022/05/26 19:00:11 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../doubly_linked_list/dlinkedlist.h"

typedef struct s_env {
	char			*key;
	char			*value;
	int				has_equal;
}	t_env;

typedef struct s_flag {
	int	n_flag;
}	t_flag;
char	**ft_split(const char *str, const char *delim);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *src, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		key_compare(void *node1, void *node2);
int		env(t_dlist *envlist);
int		export(t_dlist *envlist, int argc, char **argv);
#endif