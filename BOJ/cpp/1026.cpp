#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	int A[51], B[51];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}	
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	
	sort(A, A + N);
	sort(B, B + N, greater<int>());
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	cout << sum;
}

