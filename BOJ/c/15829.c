#include <stdio.h>
#include <math.h>
#define NUM 1234567891

int main() {
	char character[51];
	int i, L;
	unsigned long long result = 0, k = 1;
	scanf("%d", &L); scanf("%s", character);
	for (i = 0; i < L; i++) {
		result += ((character[i] - 'a' + 1) % NUM) * k;
        result %= NUM;
        k = (k * 31) % NUM; 
	}
	printf("%lld", result);
	
	return 0;
}
