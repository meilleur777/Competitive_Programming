#include <stdio.h>
#include <string.h>

int main() {
	int i, N, x;
	char order[30];
	int queue[20000];
	int start = 10000, end = 10000;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%s", order);
		
		if (!strcmp("push", order)) {
			scanf("%d\n", &x);
			queue[end++] = x;
		}
		else if (!strcmp("pop", order)) {
			if (start == end) printf("-1\n");
			else printf("%d\n", queue[start++]);
		} 
		else if (!strcmp("size", order)) {
			printf("%d\n", end - start);			
		}
		else if (!strcmp("empty", order)) {
			if (start == end) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp("front", order)) {
			if (start == end) printf("-1\n");
			else printf("%d\n", queue[start]);
		}
		else if (!strcmp("back", order)) {
			if (start == end) printf("-1\n");
			else printf("%d\n", queue[end - 1]);
		}
	}
	
	return 0;
}
