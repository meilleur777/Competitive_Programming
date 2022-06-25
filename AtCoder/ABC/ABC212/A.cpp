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

int main() {
	init_code();

	int A, B;
	cin >> A >> B;

	if (A && !B) {
		cout << "Gold";
	}
	else if (!A && B) {
		cout << "Silver";
	}
	else {
		cout << "Alloy";
	}
}
