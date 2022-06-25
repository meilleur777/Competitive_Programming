#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int A[4], sum = 0, res = 1000000;
	for (int i = 0; i < 4; i++) {
		cin >> A[i];
		sum += A[i];
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			res = min(res, abs(A[i] + A[j] - (sum - A[i] - A[j])));
		}
	}
	
	cout << res << '\n';
}

