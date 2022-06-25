#include <iostream>
using namespace std;

int main() {
	long long N, K, result; cin >> N >> K;
	int left = 1, right = K;	
	while (left <= right) {
		long long count = 0, mid = (left + right) / 2;
		for (int i = 1; i <= N; i++) count += min(mid / i, N);
		if (count >= K) result = mid, right = mid - 1;
		else left = mid + 1;
	}
	cout << result << '\n';
}

