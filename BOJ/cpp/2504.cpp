#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;

	stack<int> sk;

	for (auto c:s) {
		if (c=='(') {
			sk.push(-1);
		}
		if (c=='[') {
			sk.push(-2);
		}
		if (c==')') {
			int tmp=0;

			while (!sk.empty() && sk.top()!=-1) {
				tmp+=sk.top();
				sk.pop();
			}

			if (sk.empty() || sk.top()!=-1) {
				cout << 0;
				exit(0);
			}
			sk.pop();

			if (tmp==0) tmp=1;

			sk.push(tmp*2);
		}
		if (c==']') {
			int tmp=0;

			while (!sk.empty() && sk.top()!=-2) {
				tmp+=sk.top();
				sk.pop();
			}

			if (sk.empty() || sk.top()!=-2) {
				cout << 0;
				exit(0);
			}

			sk.pop();

			if (tmp==0) tmp=1;

			sk.push(tmp*3);
		}
	}

	int ans=0;
	while (!sk.empty()) {
		if (sk.top()<0) {
			cout << 0;
			exit(0);
		}
		
		ans+=sk.top();
		sk.pop();
	}
	cout << ans;

	return 0;
}
