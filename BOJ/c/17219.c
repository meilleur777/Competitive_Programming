#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _memo{
	char site[21];
	char password[21];
} memo;

int compare(const void *a, const void *b) {
	return strcmp((char *)(((memo *)a)->site), (char *)(((memo *)b)->site));
}

memo note[100001];

int main() {
	int i, N, M;
	char answer[21];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s %s", note[i].site, note[i].password);
	qsort(note, N, sizeof(note[0]), compare);
	for (i = 0; i < M; i++) {
		scanf("%s", answer);
		printf("%s\n", bsearch(answer, note, N, sizeof(note[0]), compare) + 21);
	}
	
	return 0;
}

