/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:05:38 by hseong            #+#    #+#             */
/*   Updated: 2022/05/20 18:17:13 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

// check s == NULL case in MacOS
char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*ret;

	size = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	while (*s)
		*ret++ = *s++;
	*ret = 0;
	return (ret - size);
}
