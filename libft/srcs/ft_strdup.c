/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:22:58 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/08 13:22:31 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;

	new_str = (char*)malloc(ft_strlen(str) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, str);
	return (new_str);
}
