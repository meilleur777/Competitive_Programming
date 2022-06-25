#include <iostream>
#include <string.h>
using namespace std;

/*추들의 무게를 합하거나, 빼서 구슬의 무게를 만들 수 있는 경우 가능하다고 한다.
이때 각 추들은 선택되거나, 합치거나, 빼거나 3가지 중에 하나의 선택지를 가지므로
총 경우는 3^추의 개수이다. 추의 최대 개수는 30개이므로 모두를 하나하나 구할 수 없다.
중요한 것은 추의 조합은 알 필요가 없다는 것이다. 어떤 무게를 추로 만들 수 있기만 하면 된다.
추의 무게가 500g이하이기 때문에 가능한 무게의 범위는 0~15000g이다.
어떤 무게를 만들 때, 하나의 추에 3가지의 선택지만이 주어져야 하므로, 
부분 문제를 "N번째 추까지 사용하여 어떤 무게 K를 만들 수 있는가"로 정의한다.*/
  
/*확인할 무게의 최대값이 40000인데, 내가 문제를 잘못 이해햇나?*/  
  
/*오답 이유 : made가 weight[current]보다 크거나 같은 경우에만 made-weight[current]가 
가능한지 검사하였는데, 만약 이번 시행에서 음수의 무게(현실에서는 구슬 쪽에 추를 올리는 것)가
나왔다고 하더라도, 다음 시행들을 거쳐 made를 0으로 만드는 것이 가능할 수 있다. 따라서
cache 크기를 늘려주고, 음수의 가능성도 고려하였다.*/  
  
int W, weight[31];
int cache[31][30001]; /*1이면 가능, 0이면 불가능, -1이면 미확인*/  

/*current부터 사용하여 made를 만들 수 있는지 반환한다.*/
int solve(int current, int made) {
	if (current == W) return !made ? 1 : 0; 
	
	int& ret = cache[current][made + 15000];
	if (ret != -1) return ret;
	if (solve(current + 1, made)) return ret = 1;
	if (solve(current + 1, made - weight[current])) return ret = 1;
	if (solve(current + 1, made + weight[current])) return ret = 1;
	return ret = 0;
}  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int N; cin >> W;
	for (int i = 0; i < W; i++) cin >> weight[i];
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x > 15000 || !solve(0, x)) cout << "N ";
		else cout << "Y ";
	}
	cout << '\n';
}

