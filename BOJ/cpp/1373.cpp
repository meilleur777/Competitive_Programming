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
	while (S.size()%3) {
		S.push_back('0');
		rotate(S.begin(), S.end()-1, S.end());
	}	
	for (int i = 0; i < S.size(); i += 3) {
		cout << (S[i]-'0')*4+(S[i+1]-'0')*2+S[i+2]-'0';
	}

	return 0;
}
