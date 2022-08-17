#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<int> day({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
	vector<string> qqq({"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"});
	int a, b;
	cin >> a >> b;
	int www=b-1;
	for (int i=0; i<a-1; i++) {
		www+=day[i];
	}
	cout << qqq[www%7];

	return 0;
}
