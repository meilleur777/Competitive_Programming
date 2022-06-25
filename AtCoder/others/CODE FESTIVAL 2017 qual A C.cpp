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

int main() {
	init_code();

	int h, w;
	cin >> h >> w;
	map<char, int> m;
	rep(i, h) rep(j, w) {
		char c;
		cin >> c;
		m[c]++;
	}
	if (h%2 && w%2) {
		int foro=1, for2=(h-1+w-1)/2;
		for (auto [a, b]:m) {
			if (b%2) {
				foro--;
				if (foro<0) {
					cout << "No";
					return 0;
				}
			}
			if (b%4 && b%2==0) {
				for2--;
				if (for2<0) {
					cout << "No";
					return 0;
				}
			}
		}
	}
	else if (h%2==0 && w%2==0) {
		for (auto [a, b]:m) {
			if (b%4) {
				cout << "No";
				return 0;
			}
		}
	}
	else {
		int for2;
		if (h%2) {
			for2=w/2;
		}
		else if (w%2) {
			for2=h/2;
		}
		for (auto [a, b]:m) {
			if (b%2) {
				cout << "No";
				return 0;
			}
			if (b%4 && b%2==0) {
				for2--;
				if (for2<0) {
					cout << "No";
					return 0;
				}
			}
		}
	}
	cout << "Yes";

	return 0;
}
