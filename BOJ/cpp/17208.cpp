#include <string.h>
#include <iostream>
using namespace std;

int N, M, K;
int x[101], y[101];
int cache[101][301][301];

/*현재 current 주문 전까지 처리했고, burger개의 치즈버거와 fries개의 감자튀김이 남았을 때,
앞으로 남은 주문 중 처리할 수 있는 주문의 최댓값 반환*/
int solve(int current, int burger, int fries) {
	if (current == N) return 0;
	
	int& ret = cache[current][burger][fries];
	if (ret != -1) return ret;
	
	ret = 0;	
	if (x[current] <= burger && y[current] <= fries) 
		ret = max(ret, solve(current + 1, burger - x[current], fries - y[current]) + 1);
	return ret = max(ret, solve(current + 1, burger, fries));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
		
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	cout << solve(0, M, K) << '\n';
}

