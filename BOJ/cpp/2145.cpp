#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (true) {
		int n;
		cin >> n;

		if (n==0) break;

		while (n>=10) {
			string str=to_string(n);

			int tmp=0;
			for (auto s:str) {
				tmp+=s-'0';
			}
			n=tmp;
		}

		cout << n << '\n';
	}

	return 0;
}
