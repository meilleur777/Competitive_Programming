#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

/*어떤 앱들을 비활성화시켜서 M 이상의 메모리를 확보해야 하는 데, 이때 비활성화시키는
앱들의 비용 합을 최소화시켜라. 가능한 모든 경우의 수 2^N, 각 앱에 대한 선택지는 on | off이다.
어떤 메모리 값을 확보하는 데 드는 최소 비용을 알아내야 하는데, 이때 메모리의 범위가 너무
크기 때문에 메모리 중심이 아닌 비용 중심으로 해결해야 한다. 어떤 비용 c로 가능한 최대 메모리의 
값이 필요한 메모리 값보다 크거나 같다면 그 비용 c가 최소 비용이다.*/

int N, c[101], m[101];
int cache[101][10001];

/*current부터 사용해서 cost로 가능한 최대 메모리값 반환*/
int solve(int current, int cost) {
	if (current == N) return 0; 
	
	int& ret = cache[current][cost];
	if (ret != -1) return ret;
		
	ret = max(0, solve(current + 1, cost));
	if (cost >= c[current]) ret = max(ret, solve(current + 1, cost - c[current]) + m[current]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int M, result;	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 0; i < N; i++) cin >> c[i];
	
	for (int i = 0; i < 10001; i++) {
		if (solve(0, i) >= M ) { result = i; break; }
	}	
	cout << result << '\n'; 
}

