#include <stdio.h>
#include <algorithm>
#include <math.h>
#define INF 0x7F7F7F7F
using namespace std;
 
/*Two Pointers*/

/*각 용액의 특성값은 유일, 혼합 용액 특성값 최대 = 1,999,999,999*/

int main() {
	int N; scanf("%d", &N);
	int arr[100001], start = 0, end = N - 1, min = INF, result1, result2;
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	while (start < end) {
		int sum = arr[start] + arr[end];
		if (abs(sum) < min) { 
			result1 = arr[start], result2 = arr[end];
			min = abs(sum); 
		}
		if (sum > 0) end--;
		else start++;
	}
	printf("%d %d\n", result1, result2);
}

