#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int t=max({a, b, c});
	cout << 3*t-a-b-c;

	return 0;
}
