#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	long long cnt0=0, cnt1=0, etc=0;
	for (int i=0; i<n; i++) {
		cnt0+=a[i]==0;
		cnt1+=a[i]==1;
		etc+=a[i]>1;
	}

	long long ans=(cnt0*(cnt0-1)/2)+cnt0*cnt1*2+cnt0*etc;
	cout << ans;

	return 0;
}
