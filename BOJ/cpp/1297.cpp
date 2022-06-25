#include <math.h>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	double D, H, W;
	cin >> D >> H >> W;
	double K = (D * D) / (H * H + W * W);
	K = sqrt(K);
	H = floor(H * K), W = floor(W * K);
	cout << H << ' ' << W << '\n';	
}

