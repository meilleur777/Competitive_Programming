#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ingredient) {
    int ret=0;
    vector<int> v;
    for (int i:ingredient) {
        if (i==1) {
            int n=v.size();
            if (n>=3 && v[n-3]==1 && v[n-2]==2 && v[n-1]==3) {
                ret++;
                for (int j=0; j<3; j++) v.pop_back();
            }
            else v.push_back(i);
        }
        else v.push_back(i);
    }
    return ret;
}
