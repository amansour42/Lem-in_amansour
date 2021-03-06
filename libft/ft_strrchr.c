/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:18:28 by amansour          #+#    #+#             */
/*   Updated: 2017/04/28 16:32:07 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char *str;

	if (!s)
		return (NULL);
	str = NULL;
	while (*s)
	{
		if (*s == (char)c)
			str = (char*)s;
		s++;
	}
	if (!*s && (char)c == '\0')
		return ((char*)s);
	return (str);
}
