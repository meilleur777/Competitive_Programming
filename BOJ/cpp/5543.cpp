#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int burger = INT_MAX;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		burger = min(burger, x);
	}
	
	int d = INT_MAX;
	for (int i = 0; i < 2; i++) {
		int x;
		cin >> x;
		d = min(d, x);
	}
	
	cout << d + burger - 50;
}

