#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int s;
	string n;
	cin >> s >> n;

	int dig=(int)n.size();
	vector<string> v(2*s+3, string(((s+2)*dig+dig), ' '));

	char hyp='-';
	char bar='|';

	function<void(int, vector<bool>)> draw=[&](int nowX, vector<bool> flag) {
		if (flag[0]) {
			for (int j=nowX+1; j<nowX+1+s; j++) {
				v[0][j]=hyp;
			}
		}
		if (flag[1]) {
			for (int j=1; j<1+s; j++) {
				v[j][nowX]=bar;
			}
		}
		if (flag[2]) {
			for (int j=1; j<1+s; j++) {
				v[j][nowX+s+1]=bar;
			}
		}
		if (flag[3]) {
			for (int j=nowX+1; j<nowX+1+s; j++) {
				v[s+1][j]=hyp;
			}
		}
		if (flag[4]) {
			for (int j=s+2; j<s+2+s; j++) {
				v[j][nowX]=bar;
			}
		}
		if (flag[5]) {
			for (int j=s+2; j<s+2+s; j++) {
				v[j][nowX+s+1]=bar;
			}
		}
		if (flag[6]) {
			for (int j=nowX+1; j<nowX+1+s; j++) {
				v[2*s+2][j]=hyp;
			}
		}
	};

	vector<vector<bool>> toDraw(10);
	toDraw[0]={1, 1, 1, 0, 1, 1, 1};
	toDraw[1]={0, 0, 1, 0, 0, 1, 0};
	toDraw[2]={1, 0, 1, 1, 1, 0, 1};
	toDraw[3]={1, 0, 1, 1, 0, 1, 1};
	toDraw[4]={0, 1, 1, 1, 0, 1, 0};
	toDraw[5]={1, 1, 0, 1, 0, 1, 1};
	toDraw[6]={1, 1, 0, 1, 1, 1, 1};
	toDraw[7]={1, 0, 1, 0, 0, 1, 0};
	toDraw[8]={1, 1, 1, 1, 1, 1, 1};
	toDraw[9]={1, 1, 1, 1, 0, 1, 1};

	for (int i=0; i<dig; i++) {
		int c=n[i]-'0';
		int nowX=i*(s+3);
		draw(nowX, toDraw[c]);
	}

	for (int i=0; i<2*s+3; i++) {
		for (auto c:v[i]) cout << c;
		cout << '\n';
	}

	return 0;
}
