#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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
	S.pop_back();
	for (int i=S.size()-1; i>=0; i--) {
		if (S.size()%2) {
			S.pop_back();
		}
		else {
			string a=string(S.begin(), S.begin()+S.size()/2);
			string b=string(S.begin()+S.size()/2, S.end());
			if (a==b) {
				cout << S.size();
				return 0;
			}
			S.pop_back();
			S.pop_back();
		}
	}
 
	return 0;
}
