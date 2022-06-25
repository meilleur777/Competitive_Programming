#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; 
int A[501];
vector<int> v;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> N;
		v.clear();
		v.push_back(-1);
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < N; i++) {
			if (v.back() < A[i]) v.push_back(A[i]);
			else {
				auto t = lower_bound(v.begin(), v.end(), A[i]);
				*t = A[i];
			}
		}
		cout << (v.size() - 1) << '\n';
	}	
}

