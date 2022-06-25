#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string x;
	cin >> x;
	int cnt=0;
	while (x.size()>1) {
		int a=0;
		for (auto i:x) a+=i-'0';
		x=to_string(a);
		cnt++;
	}
	int res=stoi(x);
	cout << cnt << '\n';
	if (res%3) cout << "NO";
	else cout << "YES";

	return 0;
}
