#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, c;
	cin >> n >> c;
	vector<int> w(n+1, 0);
	for (int i=0; i<n; i++) {
		cin >> w[i+1];
	}

	int s=1, e=1;

	vector<int> psum(n+2, 0);
	psum[1]++;
	psum[2]--;

	int sum=w[1];

	while (s<=n) {
		if (e+1>n) {
			sum-=w[s];
			s++;
		}
		else if (sum+w[e+1]>c) {
			sum-=w[s];
			s++;
		}
		else {
			e++;
			sum+=w[e];
		}

		if (s<=e) {
			psum[s]++;
			psum[e+1]--;
		}
		}

	for (int i=0; i<n; i++) {
		psum[i+1]+=psum[i];
	}

	for (int i=1; i<=n; i++) {
		cout << psum[i] << '\n';
	}

	return 0;
}
