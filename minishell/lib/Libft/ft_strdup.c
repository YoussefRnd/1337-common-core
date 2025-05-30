/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:30:49 by yboumlak          #+#    #+#             */
/*   Updated: 2024/09/08 00:34:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (s1 == NULL)
	{
		free(str);
		return (NULL);
	}
	if (str != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str[size] = '\0';
	}
	return (str);
}
/*
int	main(void)
{
	char	*s;

	s = "youssef";
	printf("%s", ft_strdup(s));
}
*/
