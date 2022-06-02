/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/06/02 23:40:07 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlinkedlist.h"

int	push_front(t_dlist *list, void *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	if (list->head == NULL)
		list->tail = new_node;
	else
		list->head->prev = new_node;
	new_node->content = content;
	new_node->next = list->head;
	new_node->prev = NULL;
	list->head = new_node;
	++list->size;
	return (1);
}

int	push_back(t_dlist *list, void *content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	if (list->tail == NULL)
		list->head = new_node;
	else
		list->tail->next = new_node;
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = list->tail;
	list->tail = new_node;
	++list->size;
	return (1);
}

void	pop_front(t_dlist *list, void (*delete_content)(void *))
{
	t_node	*del_node;

	if (list->head == NULL)
		return ;
	del_node = list->head;
	list->head = list->head->next;
	if (list->head != NULL)
		list->head->prev = NULL;
	else
		list->tail = NULL;
	delete_content(del_node->content);
	free(del_node);
	--list->size;
}

void	pop_back(t_dlist *list, void (*delete_content)(void *))
{
	t_node	*del_node;

	if (list->tail == NULL)
		return ;
	del_node = list->tail;
	list->tail = list->tail->prev;
	if (list->tail != NULL)
		list->tail->next = NULL;
	else
		list->head = NULL;
	delete_content(del_node->content);
	free(del_node);
	--list->size;
}

void	pop_node(t_dlist *list, t_node *del_node, void (*delete_content)(void *))
{
	del_node->next->prev = del_node->prev;
	del_node->prev->next = del_node->next;
	delete_content(del_node->content);
	free(del_node);
	--list->size;
}