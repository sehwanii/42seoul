/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:18:37 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/13 20:59:02 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>	//ㅈㅣ우기
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
	int				fd;
	int				malloc_size;
}					t_list;

char	*get_next_line(int fd);


size_t	ft_strlen(const char *s);
size_t	ft_strchr(const char *s, int c);
int	paste(char **dst, char *src, size_t start, size_t end);
int	parse_buffer(char *read_buf, char **ret_buf, char **prev_buf, int *malloc_size);
int	init_buffer(char **ret_buf, char **prev_buf, int *malloc_size);
char	*ft_realloc(char *s);
#endif
