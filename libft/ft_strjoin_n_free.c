/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:43:59 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/02 17:51:50 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_n_free(char *s1, char *s2, int del)
{
	char	*result;

	if (s1 && s2)
	{
		result = (char *)malloc(sizeof(char) * (ft_strlen(s1)
					+ ft_strlen(s2) + 1));
		if (result == NULL)
			return (NULL);
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
		if (del == 1)
			free(s1);
		if (del == 2)
			free(s2);
		if (del == 3)
		{
			free(s1);
			free(s2);
		}
		return (result);
	}
	return (NULL);
}
