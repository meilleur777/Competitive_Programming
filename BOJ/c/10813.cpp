#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> ball(n);
	for (int i=0; i<n; i++) {
		ball[i]=i+1;
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		int t=ball[a];
		ball[a]=ball[b];
		ball[b]=t;
	}
	for (int i=0; i<n; i++) {
		cout << ball[i] << ' ';
	}

	return 0;
}
