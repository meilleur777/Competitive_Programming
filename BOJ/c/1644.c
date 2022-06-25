#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define NUM 4000000
typedef long long ll;
int ptr = 1;
ll nums[NUM] = { 0 };
bool prime[NUM];

/*Sieve of Eratosthenes
Two-Pointers(Prefix Sum)*/

void Eratos(int n) {
	memset(prime, true, NUM);
	for (int i = 2; i <= NUM; i++) {
		if (prime[i]) {
			nums[ptr] = nums[ptr - 1] + i;
			ptr++;
			for (int j = i * 2; j <= NUM; j += i) prime[j] = false;
		}
	}
} 

int main() {
	Eratos(NUM);
	int N; scanf("%d", &N);
	int count = 0, ep = 0;
	for (int sp = 0; sp < ptr; sp++) {
		while (nums[ep] - nums[sp] < N && ep < ptr) ep++;
		if (nums[ep] - nums[sp] == N) count++;
	}
	printf("%d\n", count);
}

