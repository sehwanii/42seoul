#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "./lib/libft/libft.h"

#define PATH_MAX    4096

int main(){
	DIR 			*dp;
	struct dirent	*entry;
	char 			cur_path[PATH_MAX];
	t_list			*lst;

	lst = NULL;
	if (getcwd(cur_path, PATH_MAX) == NULL) {
		fprintf(stderr, "Error: getcwd() cannot execute\n") ;
		exit(1); 
	} 
	printf("Current Directory: %s\n", cur_path) ;
	dp = opendir(cur_path);
	if (dp == NULL)
	{
		printf("%s를 열 수 없습니다.",cur_path);
		exit (1);
	}
	entry = readdir(dp);
	while (entry != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(entry->d_name));
		printf("%s\n",entry->d_name);
		entry = readdir(dp);
	}
	printf("----------------------------------------------\n");
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	closedir(dp);
}

/*
wildcard(){
	1. opendir
	2. readdir list 만들기 + file or dir의 최대 길이 구하기
	3. while(list)
		match(word)
	4. free(list)
}

match(word, max_len){
	1. if (*word == '*')
		flag = 1
	2. ft_split(temp, '*')
	3. ft_strstr
}
*/

//재귀적으로
/*
~(1)*~(2) 의 형태
~(1)은 전부 돌면서 안맞는거 딜리트
~(2)에 대해서 다시 호출
맞는게 없다면 그대로 출력
*/