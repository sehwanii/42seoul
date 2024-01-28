/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:10:46 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/29 05:56:01 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MALLOC_ERROR 	-1
# define MALLOC_OK		0
# define READ_ALL		1
# define RETURN_ALL		2
# define PARSE_SUCCESS	3

typedef struct s_list
{
	int				fd;
	char			*line;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

char	*gnl(int fd, char **line, int *flag);
int		parse_buffer(char *s, char **ret, char *line, int *flag);
int		split_word(char *s, char **ret, char *line);
int		find_node(t_list **head, t_list **node, int fd);
void	free_node(t_list **head, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
t_list	*ft_lstnew(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
