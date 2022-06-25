#include <stdio.h>
#define min(a, b) (a < b) ? a : b

int main(void) {
    char temp1, temp2 = 'A';
	int N, count = 1, i = 0, Rnum = 0, Bnum = 0;
	scanf("%d", &N);

	while (1) {
		scanf("%c", &temp1);
        
		if (temp1 == 'R') Rnum++;
		else if (temp1 == 'B') Bnum++;

		if (temp1 == temp2) count++;
		else count = 1;

		temp2 = temp1;

		if (i++ == N) break;
	}

	if (temp1 == 'R') printf("%d", min(Rnum - count, Bnum));
	else if (temp1 == 'B') printf("%d", min(Bnum - count, Rnum));

	return 0;
}
