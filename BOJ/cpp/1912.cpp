#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int arr[100001], n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int dp[100001] = { arr[0] };
	for (int i = 1; i < n; i++) 
		dp[i] = arr[i] > arr[i] + dp[i - 1] ? arr[i] : arr[i] + dp[i - 1];
	sort(dp, dp + n);
	printf("%d", dp[n - 1]);
}

