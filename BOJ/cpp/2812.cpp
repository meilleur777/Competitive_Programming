#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	int t=n-k;
	int top=0;
	vector<int> sk;
	for (int i=0; i<n; i++) {
		while (!sk.empty() && sk.back()<s[i]-'0' && k) {
			sk.pop_back();
			k--;
		}
		sk.push_back(s[i]-'0');
	}
	for (int i=0; i<t; i++) cout << sk[i];

	return 0;
}
