/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:23:07 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/11 03:08:06 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"
#include <stdlib.h>

t_lst	*lst_new(int value)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	return (new);
}

t_lst	*lst_first(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_lst	*lst_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_add_last(t_lst **lst, t_lst *new)
{
	t_lst	*node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		node = lst_last(*lst);
		node->next = new;
		new->prev = node;
		new->next = NULL;
	}
}

void	lst_clear(t_lst **lst)
{
	t_lst	*node;

	if (!lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = node;
	}
}
