#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	N *= M;
	
	while (N % 10 == 0) {
		N /= 10;
	}
	cout << N << '\n';
}

