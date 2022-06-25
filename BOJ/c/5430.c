#include <stdio.h>
#include <string.h>

int flag;		//reversed->-1
int front, back;
int arr[100001];

void solve() {
	front = back = 0; flag = 1;
	char c, p[100002]; int j = 0, n; 
	scanf("%s %d", p, &n);
	
	scanf(" %c", &c); 
	if (n) while (c != ']') scanf("%d%c", &arr[back++], &c);
	else scanf("%c", &c);
	
	while (p[j] != '\0') {
		if (p[j] == 'R') flag *= -1;
		else if (p[j] == 'D') {
			if (!(back - front)) {
				printf("error\n");
				return;
			}
			else if (flag == 1) front++;
			else if (flag == -1) back--;
		}	
		j++;
	}
			
	if (!n) {
		printf("[]\n");
		return;
	}
	
	printf("[");
	if (flag == 1) {
		for (j = front; j < back - 1; j++) printf("%d,", arr[j]);
		printf("%d", arr[back - 1]);
	}
	else if (flag == -1) {
		for (j = back - 1; j > front; j--) printf("%d,", arr[j]);
		printf("%d", arr[front]);
	}
    printf("]\n");
}

int main() {
	int i, T; scanf("%d", &T);
	for (i = 0; i < T; i++) solve();
}
