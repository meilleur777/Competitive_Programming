#include <stdio.h>
#include <algorithm>
using namespace std;

/*Two Pointers*/

/*서로 다른 양의 정수, i < j*/

int main() {
	int n; scanf("%d", &n);
	int arr[100001], count = 0, start = 0, end = n - 1;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int x; scanf("%d", &x);
	sort(arr, arr + n);
	while (start < end) {
		int sum = arr[start] + arr[end];
		if (sum == x) { count++, start++, end--; } 
		else if (sum < x) start++;
		else end--;
	}
	printf("%d\n", count);	
}

