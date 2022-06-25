#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	int number;
	char name[21];
} dictionary;

dictionary *binarySearch(dictionary *arr, int start, int end, char *key) {
	int mid = (start + end) / 2, temp = strcmp(arr[mid].name, key);
	if (!temp) return arr + mid;
	else if (start >= end) return -1;
	else if (temp > 0) binarySearch(arr, start, mid - 1, key); 
	else if (temp < 0) binarySearch(arr, mid + 1, end, key); 
}

int compare(const void* a, const void* b) {
	dictionary* m = (dictionary*)a;
	dictionary* n = (dictionary*)b;
	return strcmp(m->name, n->name);
}

dictionary dic1[100001], dic2[100001];

int main() {
	char word[21];
	int i, N, M; scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%s", word);
		dic1[i].number = dic2[i].number = i;
		strcpy(dic1[i].name, word); strcpy(dic2[i].name, word);
	}

	qsort(dic2 + 1, N, sizeof(dictionary), compare);
	
	for (i = 0; i < M; i++) {
		scanf("%s", word);
		if (isdigit(word[0])) printf("%s\n", dic1[atoi(word)].name);
		else if (isalpha(word[0])) 
			printf("%d\n", binarySearch(dic2, 1, N, word)->number);
	}
}

