#include <stdio.h>

int main() {
	bool arr[10001] = { false };
    for (int i = 1; i <= 10000; i++) {
        int a = i, b = i;
        while (a) {	
            b += a % 10;
            a /= 10;
        }
        if (b <= 10000) arr[b] = true;
    }
    for (int i = 1; i <= 10000; i++) if (!arr[i]) printf("%d\n", i);
}
