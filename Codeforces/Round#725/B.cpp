#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> A(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			sum += A[i];
		}
		
		if (sum % n) {
			cout << "-1\n";
			continue;
		}
		
		int one = sum / n;
		sort(A.begin(), A.end());
		
		int start = -1;
		for (int i = 0; i < n; i++) {
			if (A[i] > one) {
				start = i;
				break;
			}
		}
		
		if (start == -1) {
			cout << 0 << '\n';
			continue;
		}
		else {
			cout << n - start << '\n';
		}
	}	
}

