#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int> pre((int)p.size(), 0), ans;
	for (int i=1, j=0; i<(int)p.size(); i++) {
		while (j>0 && p[i]!=p[j]) {
			j=pre[j-1];
		}
		if (p[i]==p[j]) {
			j++;
			pre[i]=j;
		}
	}
	for (int i=0, j=0; i<(int)t.size(); i++) {
		while (j>0 && t[i]!=p[j]) {
			j=pre[j-1];
		}
		if (t[i]==p[j]) {
			if (j==(int)p.size()-1) {
				ans.push_back(i-(int)p.size()+1);
				j=pre[j];
			}
			else j++;
		}
	}
	cout << (int)ans.size() << '\n';
	for (auto i:ans) cout << i+1 << ' ';

	return 0;
}
