#include <stdio.h>
#include "deque.h"

int main()
{
	// Deque의 생성 및 초기화
	t_deque deq;
	dq_init(&deq);

	// 데이터 넣기 1차
	dq_add_first(&deq, 3);
	dq_add_first(&deq, 2);
	dq_add_first(&deq, 1);
	printf("< %zu >",deq.size);
	dq_add_last(&deq, 4);
	dq_add_last(&deq, 5);
	dq_add_last(&deq, 6);
	printf("< %zu >",deq.size);
	// 데이터 꺼내기 1차
	while (!dq_is_empty(&deq))
		printf("%d ", dq_pop_first(&deq));
	printf("< %zu >",deq.size);
	printf("\n");

	// 데이터 넣기 2차
	dq_add_first(&deq, 3);
	dq_add_first(&deq, 2);
	dq_add_first(&deq, 1);
	printf("< %zu >",deq.size);
	dq_add_last(&deq, 4);
	dq_add_last(&deq, 5);
	dq_add_last(&deq, 6);
	printf("< %zu >",deq.size);
	// 데이터 꺼내기 2차
	while (!dq_is_empty(&deq))
		printf("%d ", dq_pop_last(&deq));
	printf("< %zu >",deq.size);

	return 0;
}