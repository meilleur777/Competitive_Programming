#include <vector>
#include <stdio.h>
using namespace std;

int main() {
	vector<int> A(8), B(8), C;
	for (int i = 0; i < 8; i++) scanf("%1d", &A[i]);
	for (int i = 0; i < 8; i++) scanf("%1d", &B[i]);
	for (int i = 0; i < 8; i++) {
		C.push_back(A[i]);
		C.push_back(B[i]);
	}
	while (C.size() > 2) {
		for (int i = 0; i < C.size() - 1; i++) C[i] = (C[i] + C[i + 1]) % 10;
		C.pop_back();
	}
	printf("%d%d", C[0], C[1]);
}

