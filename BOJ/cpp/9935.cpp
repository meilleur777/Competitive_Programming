#include <stdio.h>
#include <string.h>

char W1[1000010], W2[40], W3[1000010];	

int main() {
	scanf("%s %s", W1, W2);
	int len1 = strlen(W1), len2 = strlen(W2);
	
	int pointer = 0;
	for (int i = 0; i < len1; i++) {
		W3[pointer++] = W1[i];
		int temp = 0;
		if (pointer < len2) continue;
		while (temp < len2 && W3[pointer - 1 - temp] == W2[len2 - 1 - temp]) temp++;
		if (temp == len2) pointer -= temp;	
	}
	
	if (!pointer) printf("FRULA\n");
	else for (int i = 0; i < pointer; i++) printf("%c", W3[i]);
}

