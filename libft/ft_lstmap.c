/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:54:58 by pjoseth           #+#    #+#             */
/*   Updated: 2019/09/21 14:27:46 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *buf;
	t_list *buf2;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	buf = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			while (buf)
			{
				buf2 = buf->next;
				free(buf);
				buf = buf2;
			}
			return (NULL);
		}
		new = new->next;
	}
	return (buf);
}
