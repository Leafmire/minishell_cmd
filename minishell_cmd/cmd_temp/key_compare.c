/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:40:48 by hseong            #+#    #+#             */
/*   Updated: 2022/05/26 18:56:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	key_compare(void *node1, void *node2)
{
	return (ft_strcmp(((t_env *)node1)->key, ((t_env *)node2)->key));
}
