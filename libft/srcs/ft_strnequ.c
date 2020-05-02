/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:18:08 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/03 16:17:37 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, int n)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		if (*s1 != *s2)
			return (0);
		else if (*s1 == '\0')
			return (1);
		s1++;
		s2++;
		n--;
	}
	return (1);
}
