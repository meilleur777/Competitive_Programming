#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cout << fixed;
	cout.precision(2);
	
	int n;
	cin >> n;
	vector<ld> a(n);
	string s;
	cin >> s;
	rep(i, n) cin >> a[i];

	stack<ld> sk;
	for (int i=0; i<(int)s.size(); i++) {
		if (isupper(s[i])) {
			sk.push(a[s[i]-'A']);
		}
		else {
			ld p=sk.top();
			sk.pop();
			ld q=sk.top();
			sk.pop();
			ld res=0;
			switch(s[i]) {
				case '+': res=p+q; break;
				case '*': res=p*q; break;
				case '-': res=q-p; break;
				case '/': res=q/p; break;
			}
			sk.push(res);
		}
	}
	cout << sk.top();

	return 0;
}
