#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	int result1 = N / 100 * 78;
	int result2 = N / 100 * 80 + (N / 100 * 20) / 100 * 78;
	cout << result1 << ' ' << result2 << '\n';	
}

