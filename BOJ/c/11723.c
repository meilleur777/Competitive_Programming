#include <stdio.h>
#include <string.h>
#define NUM 1048575			/*1111 1111 1111 1111 1111*/

int main() {
	int i, M;
	unsigned int S = 0, temp, x;
	char order[10];
	scanf("%d", &M);
	
	for (i = 0; i < M; i++) {
		S &= NUM;		/*20번째 비트 위로 전부 0으로 만들기*/ 
		scanf("%s", order);
		
		if (!strcmp("add", order)) {
			scanf("%d", &x);
			temp = 1 << (x - 1);
			S |= temp; 
		}
		else if (!strcmp("remove", order)) {
			scanf("%d", &x);
			temp = ~(1 << (x - 1));
			S &= temp;
		}
		else if (!strcmp("check", order)) {
			scanf("%d", &x);
			temp = 1 << (x - 1);
			temp &= S;
			if (temp) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp("toggle", order)) {
			scanf("%d", &x);
			temp = 1 << (x - 1);
			if (temp & S) {
				temp = ~(1 << (x - 1));
				S &= temp;
			}
			else {
				temp = 1 << (x - 1);
				S |= temp; 
			}
		}
		else if (!strcmp("all", order)) S |= NUM;
		else if (!strcmp("empty", order)) S &= 0;
	}
	
	return 0;
}

