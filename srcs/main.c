/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:13:05 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/11 03:30:32 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"
#include "merge_utils.h"
#include <stdio.h>
#include "libft.h"

static int	init_lst(t_lst **lst, char **splitted_nums)
{
	int	i;

	i = 0;
	while (splitted_nums[i])
	{
		lst_add_last(lst, lst_new(ft_atoi(splitted_nums[i++])));
		if (!lst)
			return (-1);
	}
	return (0);
}

static void	print_result(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("Element [%i] -> Value [%i]\n", i++, lst->value);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	char	**splitted_nums;

	if (argc != 2)
	{
		printf("ERROR: one argument is needed");
		return (-1);
	}
	lst = NULL;
	splitted_nums = ft_split(argv[1], ' ');
	if (init_lst(&lst, splitted_nums))
		return (-1);
	lst = merge_sort(lst);
	print_result(lst);
	return (0);
}
