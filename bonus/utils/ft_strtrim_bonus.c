/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:26:24 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/20 17:07:02 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst_tmp == NULL && src_tmp == NULL)
		return (NULL);
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, &s[start], len);
	substr[len] = 0;
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start_pos;
	int	end_pos;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_pos = 0;
	end_pos = 0;
	end_pos = ft_strlen(s1);
	if (*s1 == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[start_pos]))
		start_pos++;
	while (ft_strchr(set, s1[end_pos]))
		end_pos--;
	end_pos++;
	return (ft_substr(s1, start_pos, (end_pos - start_pos)));
}
