#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int t=b-a;
	int fine=-1;
	if (t>=1 && t<=20) fine=100;
	else if (t>=21 && t<=30) fine=270;
	else if (t>=31) fine=500;
	if (fine==-1) {
		cout << "Congratulations, you are within the speed limit!";
	}
	else {
		cout << "You are speeding and your fine is $" << fine << ".";
	}

	return 0;
}
