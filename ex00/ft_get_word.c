/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhegewal <linus.hegewald8@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:58:03 by lhegewal          #+#    #+#             */
/*   Updated: 2025/02/22 14:04:05 by lhegewal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (ft_error());
}

char	*ft_get_word(char *dict)
{
	int	i;
	int	j;
	char *word;

	i = 0;
	j = 0;
	while (dict[i] != ':')
		i++;
	i++;
	while (dict[i] == 32 || (dict[i] >= 9 && dict[i] <= 13))
		i++;
	while (dict[i] != '\n')
	{
		j++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * j);
	i = i - j;
	j = 0;
	while (dict[i] != '\n')
	{
		word[j] = dict[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	*ft_get_num(char *dict, char *num)
{
	int	i;
	int	j;
	char *dict_num;

	i = 0;
	dict_num = ft_strstr(dict, num);
	if (!dict_num)
	{
		return (ft_error());
	}
	return (ft_get_word(dict_num));
}
