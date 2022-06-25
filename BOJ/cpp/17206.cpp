#include <string.h>
#include <iostream>
using namespace std;

typedef long long ll;

ll cache[80001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 3; i <= 80000; i += 3) cache[i] += i;
	for (int i = 7; i <= 80000; i += 7) if (i % 3) cache[i] += i;
	for (int i = 1; i <= 80000; i++) cache[i] += cache[i - 1];
		
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << cache[N] << '\n';
	}
}

