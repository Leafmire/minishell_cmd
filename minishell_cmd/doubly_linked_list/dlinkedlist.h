/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:19:18 by hseong            #+#    #+#             */
/*   Updated: 2022/06/03 19:02:02 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLINKEDLIST_H
# define DLINKEDLIST_H

# include <stdlib.h>

typedef int	(*t_comp)(void *, void *);

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_dlist
{
	t_node		*head;
	t_node		*tail;
	t_node		*cur;
	size_t		size;
	size_t		idx;
	int			flag;
}				t_dlist;

t_dlist	*dlist_init(void);

// CREATE AND DELETE
int		push_front(t_dlist *list, void *content);
int		push_back(t_dlist *list, void *content);
void	pop_front(t_dlist *list, void (*delete_content)(void *));
void	pop_back(t_dlist *list, void (*delete_content)(void *));
void	pop_node(t_dlist *list, t_node *del_node,
			void (*delete_content)(void *));
void	delete_dlist(t_dlist *list, void (*delete_content)(void *));
void	empty_dlist(t_dlist *list, void (*delete_content)(void *));

// UPDATE cur
void	move_front(t_dlist *list);
void	move_back(t_dlist *list);
void	set_cur(t_dlist *list, void *content);

// READ
void	peek_front(t_dlist *list, void (*delete_content)(void *));
void	peek_back(t_dlist *list, void (*delete_content)(void *));
void	print_dlist_forward(t_dlist *list, void (*print_content)(void *));
void	print_dlist_backward(t_dlist *list, void (*print_content)(void *));

// utils
void	ft_putnbr_space(int num);
void	mergesort_dlist(t_dlist *list, t_comp comp);
t_dlist	*duplicate_dlist(t_dlist *list);

#endif
