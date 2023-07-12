#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k=1;
	cin >> n;
	for (int i=0; i<n; i++) k*=2;
	cout << (k+1)*(k+1);

	return 0;
}
