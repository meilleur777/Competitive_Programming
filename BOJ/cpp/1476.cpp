#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

const int MAX = 15 * 28 * 19 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int E, S, M;
	cin >> E >> S >> M;
	
	for (int i = 1; i < MAX; i++) {
		int a = i % 15;
		a = (a) ? a : 15;
		
		int b = i % 28;
		b = (b) ? b : 28;
		
		int c = i % 19;
		c = (c) ? c : 19;
		
		if (a == E && b == S && c == M) {
			cout << i;
			return 0;
		}	
	}	
}

