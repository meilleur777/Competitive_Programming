#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int chk[1<<20]={0};
	auto read=[&](int q) {
		return !!(chk[q/32]&(1<<(q%32)));
	};
	auto write=[&](int q) {
		chk[q/32]|=(1<<(q%32));
		return;
	};
		
	int a;
	while (cin >> a) {
		if (!read(a)) {
			cout << a << ' ';
			write(a);
		}
	}

	return 0;
}
