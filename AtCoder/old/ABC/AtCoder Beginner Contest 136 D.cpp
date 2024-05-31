#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	string S;
	cin >> S;
	vector<int> res(S.size(), 0);
	int cnt=0;
	while (S[cnt]=='L'){
		cnt++;
	}
	res[0]=cnt;
	int t=cnt;
	cnt=0;
	for (int i=t; i<S.size(); i++) {
		cnt++;
		if (i==S.size()-1) break;
		if (S[i]!=S[i+1]) {
			res[i+1]+=cnt/2;
			res[i]+=(cnt+1)/2;
			int memo=i;
			i++;
			cnt=0;
			while (S[i]=='L') {
				cnt++;
				i++;
			}
			i--;
			res[memo]+=cnt/2;
			res[memo+1]+=(cnt+1)/2;
			cnt=0;	
		}
	}
	if (cnt!=0) res[S.size()-1]=cnt;
	for (auto i : res) {
		cout << i << ' ';
	}
	return 0;
}
