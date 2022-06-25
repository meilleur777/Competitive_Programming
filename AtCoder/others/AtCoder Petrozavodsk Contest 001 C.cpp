#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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

// use endl

string query(int x) {
	cout << x << endl;
	fflush(stdout);
	string ret;
	cin >> ret;
	if (ret=="Vacant") {
		exit(0);
	}
	return ret;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<string> ans(n+1);
	ans[0]=query(0);
	int lo=1, hi=n-1;
	while (true) {
		int mid=(lo+hi)/2;
		ans[mid]=query(mid);
		if ((ans[0]==ans[mid])!=(mid%2==0)) {
			hi=mid-1;
		}
		else lo=mid+1;	
	}

	return 0;
}
