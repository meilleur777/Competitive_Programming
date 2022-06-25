#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	while (true) {
		cin >> n;
		if (n=="0") break;
		while (n.size()>1) {
			int a=0;
			for (auto c:n) a+=c-'0';
			n=to_string(a);
		}
		cout << n << '\n';
	}

	return 0;
}
