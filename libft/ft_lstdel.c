/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 16:01:30 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/05 19:31:20 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!(alst) || !(del))
		return ;
	if (*alst)
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(&(*alst), del);
	}
	alst = NULL;
}
