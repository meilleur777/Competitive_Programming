#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, T, C, P;
	cin >> N >> T >> C >> P;
	
	int temp = N / T;
	if (N % T == 0) {
		temp--;
	}  
	
	int result = temp * C * P;
	cout << result << '\n';
}

