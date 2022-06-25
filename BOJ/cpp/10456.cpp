#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

/*
n일이 지난 후의 최소 소비금액 c[n] 
-> MIN(c[n-1] + 그냥 지불, c[n-1] + 일일 티켓, c[n-7] + 주이용권, c[n-30] + 달이용권)

travel ticket의 여부가 버스 이용료에도 영향을 끼치기 때문에 더 많은 possibile choices 
c[n-1] + 그냥 지불, c[n-1] + 버스 이용권 + 기차 그냥, c[n-1] tt
c[n-7] + 버스 주 이용권 + 기차 그냥, c[n-7] + 버스 주 이용권 + 기차 주 이용권(각 일마다 상이)
c[n-7] + 기차 주 이용권, c[n-30] + 버스 달 이용권 + 기차 그냥, 
c[n-30] + 버스 달 이용권 + 기차 일/주이용권, c[n-30] + 기차 이용권  (더 있을 수도)

어떤 티켓을 샀는지는 중요하지 않기 때문에(티켓의 중복 허용),  소비금액만을 저장하면 된다.
전체 이용료와 기차 이용료를 따로 저장해야 할 듯하다. 이때 버스 이용권을 구매한 채로 
기차 이용권을 구매하려 할 때의 비용을 고려하기 위해서는 최근 1일, 7일, 30일간의 기차 이용료
최솟값이 필요하다. 정해진 기간 내의 소비 비용이기 때문에 계속해서 새로운 값을 구해주어야 한다. 
 */
 
int dp[10001] = { 0 }; 
int bus[10001] = { 0 }; 
int train[10001] = { 0 }; 

int recent7(int end) {
	int ans = 0;
	int start = (end - 6) > 0 ? (end - 6) : 1;
	for (int i = start; i < end + 1; i++) ans += MIN(train[i], 6);
	return ans;
}

int recent30(int end) {
	int temp[31] = { 0 }, k = 1;
	int start = (end - 29) > 0 ? (end - 29) : 1;
	for (int i = start; i < end + 1; i++, k++) {
		temp[k] = temp[k - 1] + MIN(train[i], 6);
		if (k > 7) temp[k] = MIN(temp[k], temp[k - 7] + 36);
		else temp[k] = MIN(temp[k], 36);
	}
	return temp[k - 1];
}


int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int a, b; scanf("%d %d", &a, &b);
			bus[i] = a, train[i] = b * 2;
		}
		
		for (int i = 1; i <= n; i++) {
			if (i < 7) {
				dp[i] = min({
					dp[i - 1] + bus[i] + train[i],
					dp[i - 1] + 3 + train[i],
					dp[i - 1] + 6,
					18 + recent7(i),
					36,
					45 + recent30(i),
					90
				});
			}
			else if (i < 30) {
				dp[i] = min({
					dp[i - 1] + bus[i] + train[i],
					dp[i - 1] + 3 + train[i],
					dp[i - 1] + 6,
					dp[i - 7] + 18 + recent7(i),
					dp[i - 7] + 36,
					45 + recent30(i),
					90
				});
			}
			else {
				dp[i] = min({
					dp[i - 1] + bus[i] + train[i],
					dp[i - 1] + 3 + train[i],
					dp[i - 1] + 6,
					dp[i - 7] + 18 + recent7(i),
					dp[i - 7] + 36,
					dp[i - 30] + 45 + recent30(i),
					dp[i - 30] + 90
				});
			}
			
			printf("%d %d %d\n", dp[i], recent7(i), recent30(i));
		}
		
		printf("%d\n", dp[n]);
	}
}

