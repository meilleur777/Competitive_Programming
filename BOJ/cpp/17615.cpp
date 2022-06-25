#include <stdio.h>
#include <algorithm>
using namespace std;

char arr[500010];

int main() {
	int N; scanf("%d", &N);
	scanf("%s", arr);
	if (N == 1) { printf("0\n"); return 0; }	
	
	int Rcount = 0;
	for (int i = 0; i < N; i++) if (arr[i] == 'R') Rcount++;
	int Bcount = N - Rcount;
	
	if (arr[0] == 'R' && arr[N - 1] == 'R') {
		int count1 = 1, count2 = 1;
		while (arr[count1] == 'R') count1++;
		while (arr[N - 1 - count2] == 'R') count2++;
		printf("%d\n", min({Bcount, Rcount - count1, Rcount - count2}));	
	}
	else if (arr[0] == 'R' && arr[N - 1] == 'B') {
		int count1 = 1, count2 = 1;
		while (arr[count1] == 'R') count1++;
		while (arr[N - 1 - count2] == 'B') count2++;
		printf("%d\n", min({Rcount - count1, Bcount - count2}));
	}
	else if (arr[0] == 'B' && arr[N - 1] == 'R') {
		int count1 = 1, count2 = 1;
		while (arr[count1] == 'B') count1++;
		while (arr[N - 1 - count2] == 'R') count2++;
		printf("%d\n", min({Bcount - count1, Rcount - count2}));
	}
	else {
		int count1 = 1, count2 = 1;
		while (arr[count1] == 'B') count1++;
		while (arr[N - 1 - count2] == 'B') count2++;
		printf("%d\n", min({Rcount, Bcount - count1, Bcount - count2}));	
	}
}
