#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n, r;
	cin >> n >> r;

	long long k=n-r;

	long long ans=0;
	for (long long i=1; i*i<=k; i++) {
		
		if (k%i!=0) continue;

		set<long long> st;

		if (i>r) st.insert(i);
		if (k/i>r) st.insert(k/i);

		for (auto i:st) ans+=i;
	}
	cout << ans;

	return 0;
}
