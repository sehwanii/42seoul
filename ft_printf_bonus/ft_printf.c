/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:53 by sehwjang          #+#    #+#             */
/*   Updated: 2023/12/23 13:56:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap; // 가변인자 리스트를 가리키는 포인터
	//size_t	idx = 0;
	//size_t	word_start = 0;
	//int	flag = FALSE;
	size_t	len;
	//char *temp;

    va_start(ap, format); // 가변인자 리스트 포인터를 첫 주소로 초기화
	len = 0;

	t_list	*head;
	parse_format(format, &head);
	print_format(format, ap, head);

	return (len);
}

t_list	*init_data(char *str, char type)
{
	t_list	*ret;
	t_data	*new;

	new = (t_data*)malloc(sizeof(t_data));
	new->flag = 0;
	new->length = 0;
	new->precision = 0;
	new->width = 0;
	new->str = str;
	new->type = type;
	ret = ft_lstnew(new);
	return ret;
}

// void parse_format(const char* format, t_list **head)
// {
// 	const size_t	format_len = ft_strlen(format);
// 	size_t idx;
// 	size_t word_start;
// 	t_list	*new;
// 	size_t ret = 0;

// 	idx = -1;
// 	while (idx < format_len)
// 	{
// 		if (format[idx] == '%')
// 		{
// 			word_start = idx;
// 			if (format[idx + 1] == '%')
// 				idx++;
// 			while (is_type(format[idx]))
// 				idx++;
// 			if(is_type(format[idx]))
// 			new = init_data(ft_substr(format, word_start, idx - word_start), 0);
// 		else
// // 			ft_lstadd_back(head, new);
// // 			f = TRUE;
// // 			word_start = idx;
			
// 		}
// 	}
// }

// int	check_format(char c)
// {
// 	if(!is_type(c) && !is_flag(c) && !ft_isdigit(c))
// 		return (0);
// 	else
// 		return (1);
// }

#include <stdbool.h>

bool	flag;

flag = false; //==0
TRUE	==1



void parse_format(const char* format, t_list **head, bool f);
{
	int idx;
	int	f;
	size_t	word_start;
	t_list	*new;
	
	word_start = 0;
	f = FALSE;
	idx = -1;
	while (format[++idx])
	{
		if (format[idx] == '%')	//처음 %
		{
			if (format[idx + 1] == '%')
			{
				idx++;
				new = init_data(ft_substr(format, word_start, idx - word_start - 1), 0);
			}
			else
			{
				new = init_data(ft_substr(format, word_start, idx - word_start), 0);
				f = TRUE;
			}
			ft_lstadd_back(head, new);
			word_start = idx;
		}
		else if (f == TRUE && is_type(format[idx]))
		{
			new = init_data(ft_substr(format, word_start, idx - word_start + 1), format[idx]);
			ft_lstadd_back(head, new);
			word_start = idx + 1;
			f = FALSE;
		}
		// else if (f == TRUE &&  is_flag(format[idx]) == 0)
		// {
		// 	new = init_data(ft_substr(format, word_start, idx - word_start), 0);
		// 	ft_lstadd_back(head, new); 
		// 	word_start = idx + 1;
		// 	f = FALSE;
		// }
	}
	t_list *cur = (*head);
	while(cur){
		printf("%s",(*head)->content);
		cur = cur->next;
	}
}

size_t	print_format(const char* str, va_list ap, t_list *head)
{
	t_list	*cur;
	(void)str;
	cur = head;
	(void)ap;
	while(cur)
	{
		//printf("str : %s, type: %d\n",((t_data*)(cur->content))->str,((t_data*)(cur->content))->type);
		if (ft_strlen(((t_data*)(cur->content))->str) != 0 && !is_type(((t_data*)(cur->content))->str[1]))
			write_string(((t_data*)(cur->content))->str);
		else if (((t_data*)(cur->content))->type == 0)
			write_string(((t_data*)(cur->content))->str);
		else if (((t_data*)(cur->content))->type == 'c')
			write_char((char)va_arg(ap, int));
		else if (((t_data*)(cur->content))->type == 's')
			write_string((char*)va_arg(ap, char*));
		else if (((t_data*)(cur->content))->type == 'p')
			ft_print_memory((void*)va_arg(ap, void(*)));
		else if (((t_data*)(cur->content))->type == 'd')
			write_int(va_arg(ap, int));
		// if (((t_data*)(cur->content))->type == 'i');
		// if (((t_data*)(cur->content))->type == 'u');
		// if (((t_data*)(cur->content))->type == 'x');
		// if (((t_data*)(cur->content))->type == 'X');
		cur = cur ->next;
	}
	return 1;
}

int write_char(char c)
{
	write(1,&c,1);
	//write(1,"\n",1);
	return 1;
}
int	write_string(char *s)
{
	ft_putstr_fd(s,1);
	//write(1,"\n",1);
	return 1;
}
int	write_int(int n)
{
	ft_putnbr_fd(n,1);
	//write(1,"\n",1);
	return 1;
}