/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:01:43 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/11 03:08:31 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"
#include <stdlib.h>

static t_lst	*lst_split(t_lst *lst)
{
	t_lst	*fast;
	t_lst	*slow;

	if (!lst || !lst->next)
		return (lst);
	fast = lst;
	slow = lst;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow->prev)
		slow->prev->next = NULL;
	slow->prev = NULL;
	return (slow);
}

static t_lst	*merge(t_lst *head, t_lst *tail)
{
	if (!head)
		return (tail);
	if (!tail)
		return (head);
	if (head->value <= tail->value)
	{
		head->next = merge(head->next, tail);
		return (head);
	}
	else
	{
		tail->next = merge(head, tail->next);
		return (tail);
	}
}

t_lst	*merge_sort(t_lst *lst)
{
	t_lst	*tail;

	if (!lst || !lst->next)
		return (lst);
	tail = lst_split(lst);
	lst = merge_sort(lst);
	tail = merge_sort(tail);
	return (merge(lst, tail));
}
