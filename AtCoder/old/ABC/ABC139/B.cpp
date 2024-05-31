#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;
 
void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
 
int main() {
	init_code();
 
	int A, B;
	cin >> A >> B;
 
	if ((B - A) % (A - 1) == 0) {
		cout << (B - 1) / (A - 1);
	}
	else {
		cout << (B - 1) / (A - 1) + 1;
	}
 
	return 0;
}