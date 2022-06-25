#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<int> A;

/*합이 x보다 크거나 같은 경우의 수 반환*/
ll big(int x) {
	ll count = 0;
	
	for (int i = 0; i < n - 1; i++) {
		int left = i + 1, right = n - 1;
		int res = n;
		
		while (left <= right) {
			int mid = (left + right) / 2;
			
			if (A[i] + A[mid] >= x) {
				res = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}
		
		count += (n - 1) - res + 1;
	}
	
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		cin >> n >> l >> r;
		A.clear();
		A.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		
		sort(A.begin(), A.end());
		
		ll bigl = big(l);
		ll bigrp1 = big(r + 1);
		
		cout << bigl - bigrp1 << '\n';
	}	
}

