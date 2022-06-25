#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char hear[500000][21], see[500000][21], answer[500000][21];

int compare(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}

int main() {
	int i, N, M; scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", hear[i]);
	for (i = 0; i < M; i++) scanf("%s", see[i]);
	qsort(hear, N, sizeof(char[21]), compare);
	qsort(see, M, sizeof(char[21]), compare);
	
	int num = 0;
	char *result;
	for (i = 0; i < N; i++) {
		if (result = (char *)bsearch(hear[i], see, M, sizeof(char[21]), compare)) 
			strcpy(answer[num++], result);
	}
	
	printf("%d\n", num);
	for (i = 0; i < num; i++) printf("%s\n", answer[i]);
}
