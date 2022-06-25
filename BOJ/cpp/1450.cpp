#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

/*Meet in the Middle*/

ll stuff[31];

void makesum(int start, int end, ll sum, vector<ll> &arr) {
	if (start > end) {
		arr.push_back(sum); 
		return;
	}
	makesum(start + 1, end, sum, arr);
	makesum(start + 1, end, sum + stuff[start], arr);
}

int main() {
	vector<ll> sum1, sum2;	
	int result = 0, N, C; scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) scanf("%d", &stuff[i]);
	makesum(0, N / 2 - 1, 0, sum1); sort(sum1.begin(), sum1.end());
	makesum(N / 2, N - 1, 0, sum2); sort(sum2.begin(), sum2.end());
	
	int start = 0, end = sum2.size() - 1;
	while (start < sum1.size() && end >= 0) {
		if (sum1[start] + sum2[end] <= C) {
			result += end + 1;
			start++;
		}
		else end--;
	}
	printf("%d\n", result);
}

