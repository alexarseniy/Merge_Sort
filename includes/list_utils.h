/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:23:51 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/11 02:27:00 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

t_lst	*lst_new(int value);
t_lst	*lst_first(t_lst *lst);
t_lst	*lst_last(t_lst *lst);
void	lst_add_last(t_lst **lst, t_lst *new);
void	lst_clear(t_lst **lst);

#endif
