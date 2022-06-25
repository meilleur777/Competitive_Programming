#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*Longest Increasing Sequence in O(nlogn)*/

int A[1000001];
vector<int> v { 0 };

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) {
		if (v.back() < A[i]) v.push_back(A[i]);
		else {
			auto t = lower_bound(v.begin(), v.end(), A[i]);
			*t = A[i];
		}
	}
	printf("%d\n", v.size() - 1);
}

