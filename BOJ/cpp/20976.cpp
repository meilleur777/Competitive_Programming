#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	sort(a.begin(), a.end());
	cout << a[1];

	return 0;
}
