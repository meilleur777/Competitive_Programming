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

	int N, A, B;
	cin >> N >> A >> B;
	string S;
	cin >> S;
	int cnt = 0, bcnt = 0;	
	rep(i, S.size()) {
		if (S[i] == 'a') {
			if (cnt < A+B) {
				cnt++;
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
		else if (S[i] == 'b') {
			bcnt++;
			if (cnt < A+B && bcnt <= B) {
				cout << "Yes\n";
				cnt++;
			}
			else {
				cout << "No\n";
			}
		}
		else {
			cout << "No\n";
		}
	}


	return 0;
}
