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
		int small, big;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			
			if (A[i] == 1) {
				small = i;
			}
			else if (A[i] == n) {
				big = i;
			}
		}		
		
		int temp;
		if (small < big) {
			temp = min(big + 1, n - small);
			temp = min(temp, small + 1 + n - big);
		}		
		else {
			temp = min(small + 1, n - big);
			temp = min(temp, big + 1 + n - small);
		}
		cout << temp << '\n';
	}	
}

