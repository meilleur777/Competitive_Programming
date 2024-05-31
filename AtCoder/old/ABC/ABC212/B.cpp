#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

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

vector<int> pin;

bool chk1() {
	for (int i = 0; i < 3; i++) {
		if (pin[i] != pin[i + 1]) {
			return false;
		}
	}
	return true;
}

bool chk2() {
	for (int i = 0; i < 3; i++) {
		if ((pin[i] + 1) % 10 != pin[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	init_code();

	string temp;
	cin >> temp;
	for (auto i : temp) {
		pin.push_back(i - '0');
	}

	if (chk1() || chk2()) {
		cout << "Weak";
	}
	else {
		cout << "Strong";
	}
}
