#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dic[20000][51];

int cpr(const void* a, const void* b) {
    char *word1 = (char *)a;
    char *word2 = (char *)b;
	int len1 = strlen(word1), len2 = strlen(word2);
    if (len1 < len2) return -1;
    else if (len1 > len2) return 1;
    else return strcmp(word1, word2);
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", &dic[i]);
    qsort(dic, N, sizeof(char[51]), cpr);
    for (int i = 0; i < N; i++) {
        if (!strcmp(dic[i], dic[i + 1])) continue;
        else printf("%s\n", dic[i]);            
    }
}
