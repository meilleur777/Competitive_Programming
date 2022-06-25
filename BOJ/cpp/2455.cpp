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
	
	int out[4], in[4];
	for (int i = 0; i < 4; i++) {
		cin >> out[i] >> in[i];
	}	
	
	int ans = -1;
	
	int temp = in[0];
	ans = max(ans, temp);
	
	temp = max(0, temp - out[1]);
	temp = min(10000, temp + in[1]);
	ans = max(ans, temp);
	
	temp = max(0, temp - out[2]);
	temp = min(10000, temp + in[2]);
	ans = max(ans, temp);
	
	cout << ans;
}

