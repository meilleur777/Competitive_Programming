#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x, N; cin >> N;
	int MAX = -1000001, MIN = 1000001;
	while (N--) {
		cin >> x;
		MAX = max(MAX, x);	
		MIN = min(MIN, x);
	}
	cout << MIN << ' ' << MAX << '\n';	
}

