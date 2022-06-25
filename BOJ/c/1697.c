#include <stdio.h>
#define MAX 100000 + 1

int front = 0, back = 0;
int queue[200000];
int check[100001] = { 0 };

int main() {
	int N, K; scanf("%d %d", &N, &K);
	
	queue[back++] = N;
    check[queue[front]] = 1;
	while (front < back) {
        int temp = queue[front++];
        
		if (temp == K) {
			printf("%d\n", check[temp] - 1);
			return 0;
		}
        
        int i, num;
        for (i = 0; i < 3; i++) {
        	switch (i) {
        		case 0: num = temp + 1; break;
				case 1: num = temp - 1; break;
				case 2: num = temp * 2; break;
			}
			
			if (num >= 0 && num < 2 * MAX && !check[num]) {
				check[num] = check[temp] + 1;
				queue[back++] = num;
			} 
		}
	}
}
