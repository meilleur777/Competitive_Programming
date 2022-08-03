#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	sort(a.begin(), a.end());
	int sum=0;
	for (int i=0; i<n; i++) {
		if (sum+1<a[i]) {
			cout << sum+1;
			return 0;
		}
		sum+=a[i];
	}
	cout << sum+1;

	return 0;
}
