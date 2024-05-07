#include <bits/stdc++.h>
using namespace std;

//# of brown = x*y - (x-2)*(y-2)
//# of yellow = (x-2)*(y-2)
vector<int> solution(int brown, int yellow) {
    for (int y=3; y*y<=(brown+yellow); y++) {
        if ((brown+yellow)%y!=0) continue;
        int x=(brown+yellow)/y;
        if ((x-2)*(y-2)==yellow) return vector({x, y});
    }
}