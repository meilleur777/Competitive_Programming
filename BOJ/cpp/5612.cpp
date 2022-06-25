#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	int n, m;
	cin >> n >> m;
	int result = m;
	for (int i = 0; i < n; i++) {
		int in, out; cin >> in >> out;
		m = m + in - out;
		if (m < 0) { result = 0; break; }
		result = max(result, m);
	}
	cout << result << '\n';
}

