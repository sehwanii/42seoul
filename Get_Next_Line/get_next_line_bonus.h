/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:10:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/01/26 20:12:57 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MALLOC_ERROR 	-1
# define MALLOC_OK		0

typedef struct s_list
{
	int				fd;
	char			*line;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd, char **line, int *flag);
//char	*get_next_line_man(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_realloc(char *s);
int		parse_buffer(char *s, char **ret, char *line, int *flag);
int		split_word(char *s, char **ret, char *line);
char	*gnl(int fd);
int		find_node(t_list **head, t_list **node, int fd);

t_list	*ft_lstnew(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
#endif