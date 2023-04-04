/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:40:19 by tturto            #+#    #+#             */
/*   Updated: 2021/12/02 18:42:35 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*list;

	list = *alst;
	while (*alst != NULL)
	{
		node = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = node;
	}
	list = NULL;
}
