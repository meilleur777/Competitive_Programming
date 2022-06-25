#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int cnt=0;
	string s;
	getline(cin, s);
	if (s==" ") {
		cout << 0;
		return 0;
	} 
	for (int i=1; i<s.size()-1; i++) cnt+=s[i]==' ';
	cout << cnt+1;

	return 0;
}
