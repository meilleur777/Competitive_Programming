#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	long long sum=0;
	for (int i=0; i<n; i++) {
		sum+=v[i].second;
	}
	sum=(sum+1)/2;

	sort(v.begin(), v.end());

	long long tmpsum=0;
	for (int i=0; i<n; i++) {
		tmpsum+=v[i].second;
		if (tmpsum>=sum) {
			cout << v[i].first;
			break;
		}
	}

	return 0;
}
