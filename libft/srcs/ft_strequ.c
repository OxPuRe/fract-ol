/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:51:00 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/03 16:16:42 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] - s2[i] == 0)
	{
		if (s1[i] == '\0')
		{
			if (s2[i] == '\0')
				return (1);
			else
				return (0);
		}
		else if (s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
