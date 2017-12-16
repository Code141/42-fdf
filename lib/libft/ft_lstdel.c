/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:30:46 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/16 18:30:19 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void **))
{
	if (!alst || !*alst)
		return ;
	del((void*)(*alst)->content);
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	free(*alst);
	*alst = NULL;
}
