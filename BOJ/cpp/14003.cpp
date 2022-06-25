#include <stdio.h>
#include <vector>
#include <algorithm>
#define NUM -1000000001
using namespace std;

/*Longest Increasing Sequence in O(nlogn)*/

vector<int> v { NUM };
int A[1000001], index[1000001], result[1000001];

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) {
		if (v.back() < A[i]) {
			v.push_back(A[i]);
			index[i] = v.size() - 2;
		}
		else {
			int t = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
			index[i] = t - 1;
			v[t] = A[i];
		}
	}
	
	int temp = v.size() - 2;
	printf("%d\n", temp + 1);
	for (int i = N - 1; i >= 0; i--) 
		if (index[i] == temp) result[temp--] = A[i];
	for (int i = 0; i < v.size() - 1; i++) printf("%d ", result[i]);
}


