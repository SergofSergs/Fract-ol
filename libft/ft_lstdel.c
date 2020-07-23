/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:22:25 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/25 13:51:18 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *next;

	if (!alst || !*alst || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		next = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = next;
	}
	*alst = NULL;
}
