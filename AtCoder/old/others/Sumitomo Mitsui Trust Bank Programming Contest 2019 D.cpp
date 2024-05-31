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

string S;

bool chk(int x) {
	string num;
	for (int i = 0; i < 3; i++) {
		num.push_back(x%10+'0');
		x /= 10;
	}
	int ptr = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == num[ptr]) {
			ptr++;
			if (ptr == 3) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	init_code();

	int N;
	cin >> N >> S;
	int cnt = 0;
	for (int i = 0; i < 1000; i++) {
		if (chk(i)) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
