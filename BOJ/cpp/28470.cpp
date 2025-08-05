#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n), b(n), k(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		string nw=tmp.substr(0, (int)tmp.size()-2)+tmp.substr((int)tmp.size()-1);
		k[i]=stoi(nw);
	}

	long long ans=0;
	for (int i=0; i<n; i++) {
		ans+=max(a[i]-(b[i]*k[i])/10, (a[i]*k[i])/10-b[i]);
	}
	cout << ans;

	return 0;
}
