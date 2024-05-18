#include <bits/stdc++.h>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    int ret=0;
    for (int i=m-1; i<(int)score.size(); i+=m) {
        ret+=score[i]*m;
    }
    return ret;
}