#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	int need = 0;
	while (K < __builtin_popcount(N)) {
		int temp = (N & -N);
		N += temp;
		need += temp;
	}	
	cout << need << '\n';
}

