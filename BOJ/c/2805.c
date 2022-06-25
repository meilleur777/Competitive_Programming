#include <stdio.h>
#include <stdlib.h>

int height[1000001];

int compare(const int *a, const int *b) {
	return (*a > *b) ? 1 : (*a < *b) ? -1 : 0;
}

int main() {
	int i, N, M;
	scanf("%d %d", &N, &M); /*나무의 수, 목표 나무 길이*/
	for (i = 0; i < N; i++) scanf("%d", &height[i]);
		
	qsort(height, N, sizeof(int), 
		 (int(*)(const void *, const void *))compare);
	
	/*이분 탐색을 통해 목표 나무 길이를 충족하는 높이를 찾는다.
	그 높이가 최대 높이가 아닐 수 있으므로 계속해서 이분 탐색을
	시행함으로써 최대 높이를 찾는다.*/
    unsigned long long sum, start = 0, end = height[N - 1], result;
	while (start <= end) {
		sum = 0;
		unsigned long long mid = (start + end) / 2;     //어떤 높이가 조건을 충족하는지 계산 
		for (i = 0; i < N; i++) {
			if (height[i] > mid) 
				sum += height[i] - mid;
		}
		
		if (sum >= M) { 		    //만일 조건을 충족한다면 최대 높이를 찾는다. 
			result = mid;
			start = mid + 1; 
		} 
		else end = mid - 1;	    //조건을 충족하지 못한다면 높이를 낮추어 찾는다. 
	}	
	
	printf("%lld", result);
	
	return 0;
}
