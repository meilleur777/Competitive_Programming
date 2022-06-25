#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<ll> A(N);
	int sum=0;
	rep(i, N) {
		cin >> A[i];
		sum+=A[i];
	}
	ll M;
	cin >> M;
	ll temp=*max_element(A.begin(), A.end());
	if (M>=sum) {
		cout << temp;
	}
	else {
		ll res=-1, ans;
		ll left=0, right=temp;
		while (left<=right) {
			ll sum=0;
			ll mid=(left+right)/2;
			for (int i=0; i<A.size(); i++) {
				sum+=min(A[i], mid);
			}
			if (M>=sum && sum>res) {
				res=sum;
				ans=mid;
				left=mid+1;
			}
			else {
				right=mid-1;
			}
		}
		cout << ans;
	}

	return 0;
}
