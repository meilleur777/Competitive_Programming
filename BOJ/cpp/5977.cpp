#include <queue>
#include <limits.h>
#include <iostream>
using namespace std;

typedef long long ll;

/*dp[i]를 i번째 소까지 보았을 때 얻을 수 있는 최대 합이라고 정의해보자.
이때 dp[i]는 i번째 소를 선택하지 않았을 경우 max(dp[0~i-1])(= dp[i-1])가 된다.
i번째 소를 선택한다면, 반드시 i-k~i-1번째 소 중 하나를 선택하지 않아야 한다.
이때 j(i-k<=j<=i)번째 소를 선택하지 않기로 했다고 하자. 그러면 이때 dp[i]는 
sum(j+1, i) + dp[j-1]이 된다. 이런 식으로 dp[N]을 구하면 된다. 그러나 이때 
시간복잡도는 O(N^2)으로(prefix sum 사용), N의 최댓값이 10만인 것을 고려하면 너무 크다.
dp[i] = psum[i] - psum[j] + dp[j-1]이고, i-k-1<=j<=i인 모든 j에 대해 max를 찾아야 한다. 
마지막의 연속된 K개의 값들을 정렬된 순서로 가지고 있을 수 있다면, 선형시간이 가능하다. 
BOJ 11003에서 이미 사용한 방법으로 해결할 수 있다. 약간 다른 점이라면, i에 따라 dp의 값이 
바뀌기 때문에, -psum[j] + dp[j-1]의 값을 가지고 있어야 한다는 것이다.*/

int A[100002], cache[100002], psum[100002] = { 0 };
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K; cin >> N >> K;
	deque<pair<int, int> > dq;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];	
		psum[i] = psum[i - 1] + A[i];
	}
	for (int i = 1; i <= N; i++) {
		while (!dq.empty() && dq.front().second < i - K) dq.pop_front();
		cache[i] = -psum[i] + cache[i - 1]; 
		while (!dq.empty() && dq.back().first <= cache[i]) dq.pop_back();
		dq.push_back({ cache[i], i });		
		
		/*이 부분에서 실제 최댓값을 구해준다.*/		
		cache[i] = psum[i] + dq.front().first;
		if (i <= K) cache[i] = max(cache[i], psum[i]);
	}	
	cout << cache[N] << '\n';
}

