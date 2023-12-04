/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:41:39 by delim             #+#    #+#             */
/*   Updated: 2023/11/09 18:26:17 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_words(const char *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

void free_str(char **new_arr, int index)
{
    if (!new_arr[index])
    {
        while (index >= 0)
        {
            free(new_arr[index]);
            index --;
        }
        free(new_arr);
    }
}

void add_str(char const *s, char **new_arr, char c)
{
    int i;
    int index;
    int start;
    int len;

    i = 0;
    index = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        len = i - start;
        new_arr[index] = ft_substr(s, start, len);
        free_str(new_arr, index);
        index++;
    }
    new_arr[index] = NULL;
}

char **ft_split(char const *s, char c)
{
    char **new_arr;

    new_arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!new_arr)
        return (NULL);
    add_str(s, new_arr, c);
    if (new_arr == NULL)
        return (NULL);
    return (new_arr);
}
