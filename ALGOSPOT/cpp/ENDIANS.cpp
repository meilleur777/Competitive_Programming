#include <iostream>
using namespace std;

unsigned converse(unsigned N) {
	unsigned arr[4] = { 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF };
	for (int i = 0; i < 4; i++) arr[i] &= N;
	return (arr[0] >> 24) + (arr[1] >> 8) + (arr[2] << 8) + (arr[3] << 24);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		unsigned N; cin >> N;
		cout << converse(N) << '\n';
	}	
}

