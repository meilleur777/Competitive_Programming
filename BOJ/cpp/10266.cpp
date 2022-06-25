#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int q=360000;
	string s(q, '0'), p;
	p=s;
	rep(i, n) {
		int a;
		cin >> a;
		s[a]++;
	}
	rep(i, n) {
		int a;
		cin >> a;
		p[a]++;
	}
	s+=s;
	vector<int> fail(q, 0);
	for (int i=1, j=0; i<q; i++) {
		while (j>0 && p[i]!=p[j]) j=fail[j-1];
		if (p[i]==p[j]) {
			j++;
			fail[i]=j;
		}
	}
	for (int i=1, j=0; i<2*q-1; i++) {
		while (j>0 && s[i]!=p[j]) j=fail[j-1];
		if (s[i]==p[j]) {
			if (j==q-1) {
				cout << "possible";
				return 0;
			}
			else j++;
		}
	}
	cout << "impossible";

	return 0;
}
