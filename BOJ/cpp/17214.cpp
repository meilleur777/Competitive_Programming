#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	string s;
	cin >> s;
	if (s=="0") {
		cout << "W";
		return 0;
	}
	if (s.find('x')==string::npos) {
		if (s=="-1") cout << "-";
		else if (s!="1") cout << s;
		cout << "x+W";
		return 0;
	}
	int a=stoi(s.substr(0, s.find('x')));
	string b=s.substr(s.find('x')+1);
	a/=2;
	if (a==-1) cout << "-";
	else if (a!=1) cout << a;
	if (b.empty()) {
		cout << "xx+W";
	}
	else {
		cout << "xx";
		if (b=="-1") cout << "-";
		else if (b!="+1") cout << b;
		else cout << "+";
		cout << "x+W";	
	}

	return 0;
}
