#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<vector<bool>> vis(2, vector<bool>(5e5+1, false));
	int time=0;
	queue<int> q1;
	q1.push(n);
	vis[0][n]=true;
	auto print=[](int a) {
		cout << a;
		exit(0);
	};
	while (true) {
		int nowk=k+time*(time+1)/2;
		if (nowk>5e5) break;
		if (vis[time%2][nowk]) {
			print(time);
		}
		queue<int> q2;
		while (!q1.empty()) {
			int now=q1.front();
			q1.pop();
			if (now==nowk) {
				print(time);
			}
			if (now-1>=0 && !vis[(time+1)%2][now-1]) {
				q2.push(now-1);
				vis[(time+1)%2][now-1]=true;
			}
			if (now+1<=5e5 && !vis[(time+1)%2][now+1]) {
				q2.push(now+1);
				vis[(time+1)%2][now+1]=true;
			}
			if (now && now*2<=5e5 && !vis[(time+1)%2][now*2]) {
				q2.push(now*2);
				vis[(time+1)%2][now*2]=true;
			}
		}
		q1=q2;
		time++;
	}
	cout << -1;

	return 0;
}
